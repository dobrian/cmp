const audioCtx = new AudioContext();

const oscillator = audioCtx.createOscillator();
oscillator.frequency.value = 220;
oscillator.type = "sawtooth";
const oscillatorGain = audioCtx.createGain();
oscillatorGain.gain.setValueCurveAtTime(
    new Float32Array([0, 0.3, 1, 0.3, 0]),
    audioCtx.currentTime,
    4);

oscillator.connect(oscillatorGain);
oscillatorGain.connect(audioCtx.destination);

oscillator.start();
