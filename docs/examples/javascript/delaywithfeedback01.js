"use strict"

const ctx = new window.AudioContext();
const snd = new Audio( "../../sounds/my.mp3" );
const sndsrc = ctx.createMediaElementSource( snd );
const volume = ctx.createGain();
const delay = ctx.createDelay(1.); // maxDelayTime, 1 second by default
const delayGain = ctx.createGain();
const feedback = ctx.createGain();
const startStop = document.getElementById("startStop");
const volumeFader = document.getElementById("volumeFader");
const delayTimeFader = document.getElementById("delayTimeFader");
const delayGainFader = document.getElementById("delayGainFader");
const feedbackFader = document.getElementById("feedbackFader");
const volumeDisplay = document.getElementById("volumeDisplay");
const delayTimeDisplay = document.getElementById("delayTimeDisplay");
const delayGainDisplay = document.getElementById("delayGainDisplay");
const feedbackDisplay = document.getElementById("feedbackDisplay");
const userInfo = document.getElementById("userInfo");

volume.gain.value = 1.;
delay.delayTime.value = 0.5;
delayGain.gain.value = 0.5012;
feedback.gain.value = 0.

sndsrc.connect( volume );
volume.connect( delay );
delay.connect( delayGain );
delayGain.connect( feedback );
feedback.connect( delay );
delayGain.connect( ctx.destination );
volume.connect( ctx.destination );

snd.onended = function() { // reset the button when playback ends
  startStop.value = "Start";
}

function toggleSound( userPlayStatus ) {
  if ( startStop.value === "Start" ) {
    startStop.value = "Stop";
    ctx.resume(); // in case context was suspended by browser
    snd.play();
  }
  else {
    startStop.value = "Start";
    snd.pause();
  }
}

function setVolume( userVolume ) {
  if ( userVolume != 0 ) {
    volumeDisplay.innerHTML = userVolume-50;
    volume.gain.exponentialRampToValueAtTime( Math.pow( 10., 0.05*(userVolume-50) ), ctx.currentTime+0.01);
  }
  else {
    volumeDisplay.innerHTML = "-INF";
    volume.gain.linearRampToValueAtTime( 0., ctx.currentTime+0.01);
  }
}

function setDelayTime( userDelayTime ) {
  delayTimeDisplay.innerHTML = (userDelayTime*0.01).toFixed(2);
  delay.delayTime.linearRampToValueAtTime( userDelayTime*0.01, ctx.currentTime+0.01);
}

function setDelayGain( userDelayGain ) {
  if ( userDelayGain != 0 ) {
    delayGainDisplay.innerHTML = userDelayGain-50;
    delayGain.gain.exponentialRampToValueAtTime( Math.pow( 10., 0.05*(userDelayGain-50) ), ctx.currentTime+0.01);
  }
  else {
    delayGainDisplay.innerHTML = "-INF";
    delayGain.gain.linearRampToValueAtTime( 0., ctx.currentTime+0.01);
  }
}

function setFeedback( userFeedback ) {
  if ( userFeedback != 0 ) {
    feedbackDisplay.innerHTML = userFeedback-50;
    feedback.gain.exponentialRampToValueAtTime( Math.pow( 10., 0.05*(userFeedback-50) ), ctx.currentTime+0.01);
  }
  else {
    feedbackDisplay.innerHTML = "-INF";
    feedback.gain.linearRampToValueAtTime( 0., ctx.currentTime+0.01);
  }
}
