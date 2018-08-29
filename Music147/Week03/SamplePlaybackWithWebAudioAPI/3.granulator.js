// Set up the AudioContext and the dac.
let audioCtx = new AudioContext();
let dac = audioCtx.destination;

// Save a space for the audio data.
let buffer = null;

// The window shape to be used by `.setValueCurveAtTime()`.
let curve = new Float32Array([0, 0.3, 1, 0.3, 0]);

// Load the sound file, and store the data to our `buffer` variable.
let request = new XMLHttpRequest();
request.open("GET", "freejazz.wav", true);
request.responseType = "arraybuffer";
request.onload = () => audioCtx.decodeAudioData(request.response, (data) => buffer = data);
request.send();

// Play a random grain.
let playGrain = (startTime, grainDuration) => {

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

// Run the granulation when you click the play button.
$("#play").on("click", () => {
  // Get overlap time, grain duration, and total time from input sliders
  let overlapTime = Number($("#overlap-time").val() / 1000);
  let grainDuration = Number($("#grain-duration").val() / 1000);
  let totalTime = Number($("#total-time").val());
  let numberOfGrains = (totalTime - grainDuration) / overlapTime;

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
