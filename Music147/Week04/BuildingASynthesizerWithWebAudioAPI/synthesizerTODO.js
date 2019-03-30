////////////
// Global constants
////////////

const audioCtx = new AudioContext();

const ASCII_TO_HZ = {
  "67": 261.63,
  // TODO fill this in with more values
  // Hint: look at `asciitable.com` and `https://newt.phys.unsw.edu.au/jw/notes.html`
};


////////////
// User assignable global variables
////////////

let waveType = "sawtooth";   // base waveform
let vibratoSpeed = 6;        // vibrato speed is in Hz
let vibratoAmount = 20;      // vibrato amount is in cents (not Hz!)
let filterType = "lowpass";  // one of "lowpass", "highpass", or "bandpass"
let filterCutoff = 500;      // filter cutoff frequency in Hz


////////////
// Primary sound-producing function (you may want to break this up)
////////////

const playNote = (frequency) => {
  // Create an oscillator with a given frequency
  const oscillator = audioCtx.createOscillator();
  oscillator.frequency.value = frequency;
  oscillator.type = waveType; // taken from global variable
  const oscillatorGain = audioCtx.createGain();
  oscillator.connect(oscillatorGain);
  oscillatorGain.connect(audioCtx.destination);

  oscillator.start();

  // TODO add a modulator to implement user-adjustable vibrato

  // TODO add a filter node to implement a user-adjustable filter

  // TODO customize an envelope with the `setValueCurveAtTime` method

  // TODO stop the note
};


////////////
// User input
////////////

$(document).keydown((event) => {
  let asciiValue = event.which;
  if (ASCII_TO_HZ.hasOwnProperty(asciiValue)) {
    let hz = ASCII_TO_HZ[asciiValue];
    playNote(hz);
  }
});

$("#wave-type").on("change", () => {
  waveType = $("#wave-type").val();
});

// TODO make similar functions for vibrato and filter parameters
