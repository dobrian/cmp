// This sets up a synthesizer to play notes in response to key presses in the web page "vibratosynth.html".

"use strict";

// these variables will hold info about the sound characteristics
var midipitch; // MIDI key number of note played/released (0-127)
var midivelocity; // MIDI velocity of note played/released (0-127)
var transposition; // + or - some multiple of 12 semitones
var amplitude; // peak amplitude of the note (0.-1.)
var frequency; // frequency of the carrier oscillator
var vibratoRate; // LFO modulator frequency
var vibratoDepth; // LFO modulator amplitude
var ampAttack; // attack time of amplitude envelope
var ampRelease; // release time of amplitude envelope
var masterVolume; // final gain stage
var keyboard; // map of computer keys to MIDI keys
var lastKeyDown; // keep track of last note-playing key pressed
var synthOn; // keep track of whether AudioContext is active

// these variables will point to components of the instrument
const AudioContext = window.AudioContext || window.webkitAudioContext;
var vibctx; // the audio context
var viboutput; // audio destination (connection to speakers)
var vibmasterGain; // master volume control
var vibampEnv; // amplitude envelope
var vibcarrier; // carrier oscillator
var viblfoDepth; // control of vibrato depth (LFO amplitude)
var viblfo; // low-frequency modulating oscillator for vibrato
var vibcarrierFreq; // constant source of stable carrier frequency

// set initial values
transposition = 0; // no transposition; keyboard is MIDI keys 60-72
setMidiVelocity(); // about -10 dB from maximum amplitude
setVibratoRate(); // 6 Hz by default
setVibratoDepth(); // 25 cents by default
keyboard = new Map( [[65,60],[87,61],[83,62],[69,63],[68,64],[70,65],[84,66],[71,67],[89,68],[72,69],[85,70],[74,71],[75,72]] );
// AR amplitude envelope is fixed for now
// could be user-provided ADSR later
ampAttack = 0.005;
ampRelease = 1.;
masterVolume = 1.; // will later be controllable dynamically by the user
synthOn = false; // synth must be turned on explicitly by the user

// Event Listeners, to get user input from the web page
document.getElementById( "onoff" ).addEventListener( "click", synthOnOff );
document.getElementById( "velocity" ).addEventListener( "change", setMidiVelocity );
document.getElementById( "vibratorate" ).addEventListener( "change", setVibratoRate );
document.getElementById( "vibratodepth" ).addEventListener( "change", setVibratoDepth );
document.addEventListener( "keydown", docKeydown );
document.addEventListener( "keyup", docKeyup );

// in response to a click on the "onoff" button
function synthOnOff() {
  if ( synthOn ) {
    vibctx.close();
    synthOn = false;
    document.getElementById( "onoff" ).value = "Off";
  }
  else {
    if ( createInstrument() ) { // ensure that it succeeded
      synthOn = true;
      document.getElementById( "onoff" ).value = "On";
    }
  }
}

// create audio context and vibrato synthesizer
function createInstrument() {
  vibctx = new AudioContext(); // create the audio context
  viboutput = vibctx.destination; // establish connection to speakers
  vibmasterGain = vibctx.createGain(); // master volume control
  vibampEnv = vibctx.createGain(); // amplitude envelope
  vibcarrier = vibctx.createOscillator(); // carrier oscillator
  vibcarrier.type = "sawtooth"; // make it a sawtooth wave for richness
  viblfoDepth = vibctx.createGain(); // depth of vibrato (LFO)
  viblfo = vibctx.createOscillator(); // low-frequency modulating oscillator for vibrato
  vibcarrierFreq = vibctx.createConstantSource(); // main frequency of the note
  vibmasterGain.connect( viboutput ); // connect master volume to destination (speakers)
  vibampEnv.connect( vibmasterGain ); // connect synth output to master volume control
  vibcarrier.connect( vibampEnv ); // connect carrier oscillator to amplitude envelope
  vibcarrierFreq.connect( vibcarrier.frequency ); // control the carrier oscillator's base frequency
  viblfoDepth.connect( vibcarrier.frequency ); // connect LFO gain control to carrier's vibrato
  viblfo.connect( viblfoDepth ); // connect LFO to its gain (depth) control
  vibmasterGain.gain.value = masterVolume; // pre-set master volume (constant for now)
  vibampEnv.gain.value = 0.; // will be controlled in the playNote() function
  viblfoDepth.gain.value = 0.; // will be controlled in the playNote() function
  viblfo.frequency.value = vibratoRate; //
  vibcarrier.frequency.value = 0.; // will be set in the playNote() function
  vibcarrierFreq.start( 0 ); // begin sending constant value
  vibcarrier.start( 0 ); // begin carrier oscillator processing
  viblfo.start(); // begin LFO processing
  return true; // indicate success
}

// limit velocity input between 0 and 127
function setMidiVelocity() {
  midivelocity = document.getElementById( "velocity" ).value;
  if ( midivelocity > 127 ) {
    midivelocity = 127;
    document.getElementById( "velocity" ).value = midivelocity;
  }
  else if ( midivelocity < 0 ) {
    midivelocity = 0;
    document.getElementById( "velocity" ).value = midivelocity;
  }
}

function setVibratoRate() {
  vibratoRate = document.getElementById( "vibratorate" ).value;
}

function setVibratoDepth() {
  vibratoDepth = document.getElementById( "vibratodepth" ).value;
}

function docKeydown( theKey ) {
  //  console.log( theKey.keyCode ); // check ASCII value
  let theKeyCode = theKey.keyCode; // store it in a local variable
  if ( theKeyCode === 88 ) { // 'X' or 'x', transpose up an octave
    if ( transposition <= 36 ) transposition += 12; // but not higher than +48 semitones
  }
  else if ( theKeyCode === 90 ) {  // 'Z' or 'z', transpose down an octave
    if ( transposition >= -36 ) transposition -= 12; // but not lower than -48 semitones
  }
  else if ( theKeyCode >= 65 && theKeyCode <= 90 ) { // letter key A-Z or a-z
    // play notes in response to certain letter keys, using keyCode to set midipitch
    if ( keyboard.has( theKeyCode ) ) { // see if it's defined in the MIDI keyboard
      if ( theKeyCode !== lastKeyDown ) { // if key is not already down
        lastKeyDown = theKeyCode; // keep global track of last note key pressed
        midipitch = keyboard.get( theKeyCode ); // look up MIDI key # in keyboard map
        frequency = mtof( midipitch + transposition ); // calculate note frequency
        amplitude = vtoa( midivelocity ); // calculate note amplitude
        vibratoRate = document.getElementById( "vibratorate" ).value; // check rate
        playNote();
        // document.getElementById( "info" ).innerHTML = "You played frequency " + frequency.toFixed(3) + " Hz." // report note frequency to user
      }
    }
    else {
      document.getElementById( "warnings" ).innerHTML="The '" + theKey.key + "' key is not considered part of this music keyboard.";
    }
  }
}

function docKeyup( theKey ) {
  if ( theKey.keyCode === lastKeyDown ) {
    lastKeyDown = -1; // clear this variable (so note can be played again)
    stopNote(); // turn gain down
  };
}

// not yet implemented for master volume control
// function docMouseY( theMouseMove ) {
//   let ynorm = (theMouseMove.y/window.innerHeight);
//   if ( ynorm < 0.995 ) { // if the mouse is in the top 99.5% of the window
//     masterVolume = Math.pow(10.,-3.*ynorm); // 0 dB to almost -60 dB
//   } else { masterVolume = 0.; } // totally off
//   // console.log( masterVolume ); // check result
// }

function playNote() {
  // vibcarrier.frequency.value = frequency; // this would be okay for unmodulated carrier oscillator, but we want to add audio-rate frequency modulation and low-frequency vibrato
  vibcarrierFreq.offset.value = frequency;
  viblfo.frequency.value = vibratoRate;
  viblfoDepth.gain.value = frequency*centstoratio(vibratoDepth)-frequency;
  vibampEnv.gain.cancelScheduledValues( 0. ); // stop any ongoing fade
  vibampEnv.gain.linearRampToValueAtTime( amplitude, vibctx.currentTime+ampAttack );
}

function stopNote() {
  vibampEnv.gain.cancelScheduledValues( 0. ); // stop any ongoing fade
  vibampEnv.gain.exponentialRampToValueAtTime( 0.0001, vibctx.currentTime+ampRelease );
}

// These are generally useful functions, so they would be best placed in a separate file of utility functions, so that they could be reusable by any web page.

// Return the frequency of a given pitch (a MIDI key number).
function mtof( pitch ) {
  return 440.*Math.pow(2.,(pitch-69)/12.);
}

// Return the linear amplitude equivalent of a decibel value.
function dbtoa( decibels ) {
  return Math.pow(10.,decibels*0.05);
}

// Return amplitude equivalent of velocity, scaled as -50 db to 0 dB.
function vtoa( velocity ) {
  if ( velocity == 0 ) {
    return 0.;
  }
  else {
    return Math.pow(10.,(velocity-127)*.02);
  }
}

// Convert cents (pitch interval) to a multiplication factor for frequency
function centstoratio( cents ) {
  return Math.pow(2.,cents/1200.);
}

///////////////////// using switch instead of Map() //////////////////////
/*
switch( theKeyCode ) {
  case 65 : // 'A' or 'a'
    lastKeyDown = theKey.keyCode; // store it in a global variable for later reference
    midipitch = 60;
    break;
  case 87 : // 'W' or 'w'
    lastKeyDown = theKey.keyCode;
    midipitch = 61;
    break;
  case 83 : // 'S' or 's'
    lastKeyDown = theKey.keyCode;
    midipitch = 62;
    break;
  case 69 : // 'E' or 'e'
    lastKeyDown = theKey.keyCode;
    midipitch = 63;
    break;
  case 67 : // 'D' or 'd'
    lastKeyDown = theKey.keyCode;
    midipitch = 64;
    break;
  case 70 : // 'F' or 'f'
    lastKeyDown = theKey.keyCode;
    midipitch = 65;
    break;
  case 84 : // 'T' or 't'
    lastKeyDown = theKey.keyCode;
    midipitch = 66;
    break;
  case 71 : // 'G' or 'g'
    lastKeyDown = theKey.keyCode;
    midipitch = 67;
    break;
  case 89 : // 'Y' or 'y'
    lastKeyDown = theKey.keyCode;
    midipitch = 68;
    break;
  case 72 : // 'H' or 'h'
    lastKeyDown = theKey.keyCode;
    midipitch = 69;
    break;
  case 85 : // 'U' or 'u'
    lastKeyDown = theKey.keyCode;
    midipitch = 70;
    break;
  case 74 : // 'J' or 'j'
    lastKeyDown = theKey.keyCode;
    midipitch = 71;
    break;
  case 75 : // 'K' or 'k'
    lastKeyDown = theKey.keyCode;
    midipitch = 72;
    break;
  default :
    document.getElementById( "warnings" ).innerHTML="The '" + theKey.key + "' key is not considered part of this music keyboard.";
}
*/
