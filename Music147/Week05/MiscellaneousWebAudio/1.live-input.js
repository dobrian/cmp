const audioCtx = new AudioContext();
if (navigator.mediaDevices) {
  navigator.mediaDevices.getUserMedia({"audio": true}).then((stream) => {
    const microphone = this.context.createMediaStreamSource(stream);

  }).catch((err) => {
    // browser unable to access microphone
    // (check to see if microphone is attached)
  });
} else {
  // browser unable to access media devices
  // (update your browser)
}

