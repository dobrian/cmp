const audioCtx = new AudioContext();

const oscs = [];

for (let freq = 110; freq <= 1100; freq += 110) {
  let osc = audioCtx.createOscillator();
  osc = audioCtx.createOscillator();
  osc.frequency.value = freq;
  oscs.push(osc);
}

oscs.forEach((osc) => {
  osc.connect(audioCtx.destination);
  osc.start();
});

