let audioCtx = new AudioContext();
let dac = audioCtx.destination;
let buffer = null;
let curve = new Float32Array([0, 0.3, 1, 0.3, 0]);

let request = new XMLHttpRequest();
request.open("GET", "freejazz.wav", true);
request.responseType = "arraybuffer";
request.onload = () => audioCtx.decodeAudioData(request.response, (data) => buffer = data);
request.send();

let playRandomGrain = (startTime, grainDuration) => {
  // Create a node to play from a buffer.
  let grain = audioCtx.createBufferSource();
  grain.buffer = buffer;

  // Create a node to control the buffer's gain.
  let grainGain = audioCtx.createGain()
  grainGain.connect(dac);

  // Create a window.
  grainGain.gain.setValueAtTime(0, startTime);
  grainGain.gain.setValueCurveAtTime(curve, startTime, grainDuration);
  grain.connect(grainGain);

  // Choose a random place to start.
  let offset = Math.random() * (buffer.duration - grainDuration)

  // Play the grain.
  grain.start(startTime, offset, grainDuration);
};

$("#play").on("click", () => {
  /*
  let overlapTime = Number($("#overlap-time").val() / 1000);
  let grainDuration = Number($("#grain-size").val() / 1000);
  let numberOfGrains = Number($("#number-of-grains").val());
  for (let i = 0; i < numberOfGrains; i += 1) {
    playRandomGrain(i * overlapTime, grainDuration);
  }
  */

  for (let i = 0; i < 1000; i += 1) {
    playRandomGrain(i * 0.01, 0.05);
  }
});
