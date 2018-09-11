// Adapted from "https://developer.mozilla.org/en-US/docs/Web/API/AnalyserNode

// Create the audio context and an analyser node.
var audioCtx = new(window.AudioContext || window.webkitAudioContext)();
var analyser = audioCtx.createAnalyser();

// Set FFT parameters
analyser.fftSize = 2048;
var bufferLength = analyser.frequencyBinCount;
var dataArray = new Uint8Array(bufferLength);
analyser.getByteTimeDomainData(dataArray);

// Get a canvas defined with ID "oscilloscope"
var canvas = document.getElementById("oscilloscope");
var canvasCtx = canvas.getContext("2d");

// Draw an oscilloscope of the current audio source
function draw() {

  requestAnimationFrame(draw);

  analyser.getByteTimeDomainData(dataArray);

  canvasCtx.fillStyle = "rgb(200, 200, 200)";
  canvasCtx.fillRect(0, 0, canvas.width, canvas.height);

  canvasCtx.lineWidth = 2;
  canvasCtx.strokeStyle = "rgb(0, 0, 0)";

  canvasCtx.beginPath();

  var sliceWidth = canvas.width * 1.0 / bufferLength;
  var x = 0;

  for (var i = 0; i < bufferLength; i++) {

    var v = dataArray[i] / 128.0;
    var y = v * canvas.height / 2;

    if (i === 0) {
      canvasCtx.moveTo(x, y);
    } else {
      canvasCtx.lineTo(x, y);
    }

    x += sliceWidth;
  }

  canvasCtx.lineTo(canvas.width, canvas.height / 2);
  canvasCtx.stroke();
}

draw();

// Access the microphone, and connect it to the analyser
if (navigator.mediaDevices) {
  navigator.mediaDevices.getUserMedia({"audio": true}).then((stream) => {
    const microphone = audioCtx.createMediaStreamSource(stream);
    microphone.connect(analyser);
  }).catch((err) => {
    alert("browser unable to access microphone!");
  });
} else {
  alert("browser unable to access media devices!");
}
