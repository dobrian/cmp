const audioCtx = new AudioContext();
if (navigator.mediaDevices) {
  navigator.mediaDevices.getUserMedia({"audio": true}).then((stream) => {
    const mediaRecorder = new MediaRecorder(stream);
    let chunks = [];

    mediaRecorder.ondataavailable = (eve) => {
      chunks.push(eve.data);
    }

    mediaRecorder.onstop = (eve) => {
      const audio = new Audio();
      audio.setAttribute("controls", "");
      $("#sound-clip").append(audio);
      const blob = new Blob(chunks, { 'type' : 'audio/ogg; codecs=opus' });
      chunks = [];
      const audioURL = window.URL.createObjectURL(blob);
      audio.src = audioURL;
    };

    $("#record").on("click", () => {
      mediaRecorder.start();
    });

    $("#stop").on("click", () => {
      mediaRecorder.stop();
    });

    
  }).catch((err) => {
    // browser unable to access microphone
    // (check to see if microphone is attached)
  });
} else {
  // browser unable to access media devices
  // (update your browser)
}


