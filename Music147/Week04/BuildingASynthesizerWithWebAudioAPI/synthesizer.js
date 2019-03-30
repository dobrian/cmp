////////////
// Global constants
////////////

const audioCtx = new AudioContext();

const ASCII_TO_HZ = {
  "65": 261.63, // ASCII: a | NOTE: C4
  "83": 293.67, // ASCII: s | NOTE: D4
  "68": 329.63, // ASCII: d | NOTE: E4
  "70": 349.23, // ASCII: f | NOTE: F4
  "71": 392,    // ASCII: g | NOTE: G4
  "72": 440,    // ASCII: h | NOTE: A4
  "74": 493.88, // ASCII: j | NOTE: B4
  "75": 523.25, // ASCII: k | NOTE: C5
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
  const oscillator = audioCtx.createOscillator();
  oscillator.frequency.value = frequency;
  oscillator.type = waveType; // taken from global variable
  const oscillatorGain = audioCtx.createGain();
  oscillator.connect(oscillatorGain);

  const modulator = audioCtx.createOscillator();
  modulator.frequency.value = vibratoSpeed;
  const modulatorGain = audioCtx.createGain();
  modulatorGain.gain.value = vibratoAmount;
  modulator.connect(modulatorGain);
  modulatorGain.connect(oscillator.frequency);

  // Create the filter
  const filter = audioCtx.createBiquadFilter();
  filter.type = filterType;
  filter.frequency.value = filterCutoff;
  oscillatorGain.connect(filter);
  filter.connect(audioCtx.destination);

  // Start the oscillator and vibrato
  oscillator.start();
  modulator.start();

  // Create an envelope for the oscillator's gain
  oscillatorGain.gain.setValueCurveAtTime(
      new Float32Array([0, 1, 1, 1, 0.5, 0]),
      audioCtx.currentTime,
      1.5);
  oscillator.stop(audioCtx.currentTime + 1.5);
  modulator.stop(audioCtx.currentTime + 1.5);
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

$("#vibrato-speed").on("change", () => {
  vibratoSpeed = $("#vibrato-speed").val();
});

$("#vibrato-amount").on("change", () => {
  vibratoAmount = $("#vibrato-amount").val();
});

$("#filter-type").on("change", () => {
  filterType = $("#filter-type").val();
});

$("#filter-cutoff").on("change", () => {
  filterCutoff = $("#filter-cutoff").val();
});
