const audioCtx = new AudioContext();
let buffer = null;

const load = () => {
  const request = new XMLHttpRequest();
  request.open("GET", "freejazz.wav");
  request.responseType = "arraybuffer";
  request.onload = function() {
    let undecodedAudio = request.response;
    audioCtx.decodeAudioData(undecodedAudio, (data) => buffer = data);
  };
  request.send();
};

const play = () => {
  const source = audioCtx.createBufferSource();
  source.buffer = buffer;
  source.connect(audioCtx.destination);
  source.start();
};

$("#load").on("click", load);
$("#play").on("click", play);
