const audioCtx = new AudioContext();

const oscillator = audioCtx.createOscillator();
oscillator.frequency.value = 220;
oscillator.type = "sawtooth";
const oscillatorGain = audioCtx.createGain();
oscillatorGain.gain.value = 0.1;
oscillator.connect(oscillatorGain);
oscillatorGain.connect(audioCtx.destination);

const modulator = audioCtx.createOscillator();
modulator.frequency.value = 1;
const modulatorGain = audioCtx.createGain();
modulatorGain.gain.value = 1;
modulator.connect(modulatorGain);
modulatorGain.connect(oscillatorGain.gain);

oscillator.start();
modulator.start();
