const audioCtx = new AudioContext();

// Create a sawtooth wave with a frequency of 220 (aka A3).
const oscillator = audioCtx.createOscillator();
oscillator.frequency.value = 220;
oscillator.type = "sawtooth";
const oscillatorGain = audioCtx.createGain();
oscillatorGain.gain.value = 0.1;
oscillator.connect(oscillatorGain);
oscillatorGain.connect(audioCtx.destination);

// Start oscillator after 2 seconds have passed
oscillator.start(audioCtx.currentTime + 2);
