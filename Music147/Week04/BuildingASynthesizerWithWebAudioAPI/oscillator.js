const audioCtx = new AudioContext();

const oscillator = audioCtx.createOscillator();
oscillator.frequency.value = 220;
oscillator.type = "sawtooth";
const oscillatorGain = audioCtx.createGain();
oscillatorGain.gain.value = 0.1;
oscillator.connect(oscillatorGain);
oscillatorGain.connect(audioCtx.destination);

oscillator.start(audioCtx.currentTime + 2);
