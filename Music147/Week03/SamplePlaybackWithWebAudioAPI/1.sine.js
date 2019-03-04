const audioCtx = new AudioContext();
const osc = audioCtx.createOscillator();
const gain = audioCtx.createGain();
const dac = audioCtx.destination;

osc.frequency.value = 300;
gain.gain.value = 0.5;

osc.connect(gain);
gain.connect(dac);
osc.start();

osc.stop();
