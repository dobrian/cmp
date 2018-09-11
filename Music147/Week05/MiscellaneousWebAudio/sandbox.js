const audioCtx = new AudioContext();
if (navigator.mediaDevices) {
  navigator.getUserMedia({"audio": true}).then((stream) => {
    const microphone = audioCtx.createMediaStreamSource(stream);
    // microphone can now act like any other AudioNode
  }).catch((err) => {
    // browser unable to access microphone
    // (check to see if microphone is attached)
  });
} else {
  // browser unable to access media devices
  // (update your browser)
}
