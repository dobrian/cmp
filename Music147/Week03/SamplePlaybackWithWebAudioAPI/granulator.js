// Set up the AudioContext and the dac.
const audioCtx = new AudioContext();
const dac = audioCtx.destination;

// Save a space for the audio data.
let buffer = null;

// The window shape to be used by `.setValueCurveAtTime()`.
const curve = new Float32Array([0, 0.3, 1, 0.3, 0]);

// Load the sound file, and store the data to our `buffer` variable.
const request = new XMLHttpRequest();
request.open("GET", "freejazz.wav", true);
request.responseType = "arraybuffer";
request.onload = () => audioCtx.decodeAudioData(request.response, (data) => buffer = data);
request.send();

// Play a random grain.
const playGrain = (startTime, grainDuration) => {

  // Create a node to play from a buffer.
  const grain = audioCtx.createBufferSource();
  grain.buffer = buffer;

  // Create a node to control the buffer's gain.
  const grainGain = audioCtx.createGain()
  grainGain.connect(dac);

  // Create a window.
  grainGain.gain.setValueAtTime(0, startTime);
  grainGain.gain.setValueCurveAtTime(curve, startTime, grainDuration);
  grain.connect(grainGain);

  // Choose a random place to start.
  const offset = Math.random() * (buffer.duration - grainDuration)

  // Play the grain.
  grain.start(startTime, offset, grainDuration);
};

// Run the granulation when you click the play button.
$("#play").on("click", () => {
  // Get overlap time, grain duration, and total time from input sliders
  const overlapTime = Number($("#overlap-time").val() / 1000);
  const grainDuration = Number($("#grain-duration").val() / 1000);
  const totalTime = Number($("#total-time").val());
  const numberOfGrains = (totalTime - grainDuration) / overlapTime;

  // Perform the granulation
  for (let i = 0; i < numberOfGrains; i += 1) {
    playGrain(audioCtx.currentTime + i * overlapTime, grainDuration);
  }
});


// Handle slider UI.
$("#overlap-time").on("change", () => {
  $("#overlap-time-indicator").text($("#overlap-time").val() + " ms");
});
$("#grain-duration").on("change", () => {
  $("#grain-duration-indicator").text($("#grain-duration").val() + " ms");
});
$("#total-time").on("change", () => {
  $("#total-time-indicator").text($("#total-time").val() + " seconds");
});
$("#overlap-time-indicator").text($("#overlap-time").val() + " ms");
$("#grain-duration-indicator").text($("#grain-duration").val() + " ms");
$("#total-time-indicator").text($("#total-time").val() + " seconds");
