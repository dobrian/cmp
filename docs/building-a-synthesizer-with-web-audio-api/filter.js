const audioCtx = new AudioContext();

// Create an oscillator
const oscillator = audioCtx.createOscillator();
oscillator.frequency.value = 220;
oscillator.type = "sawtooth";
const oscillatorGain = audioCtx.createGain();
oscillatorGain.gain.value = 0.1;

// Create the filter
const filter = audioCtx.createBiquadFilter();
filter.type = "lowpass";
filter.frequency.value = 660;
filter.Q.value = 20;

// Create an LFO that changes the filter's cutoff frequency
const modulator = audioCtx.createOscillator();
modulator.frequency.value = 2;
modulator.type = "sawtooth";
const modulatorGain = audioCtx.createGain();
modulatorGain.gain.value = -440; // a negative gain value inverts the shape of the sawtooth wave

// Set up the signal chain
modulator.connect(modulatorGain);
modulatorGain.connect(filter.frequency);
oscillator.connect(oscillatorGain);
oscillatorGain.connect(filter);
filter.connect(audioCtx.destination);

oscillator.start();
modulator.start()
