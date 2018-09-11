const audioCtx = new AudioContext();
const audio = new Audio("freejazz.wav");
const source = audioCtx.createMediaElementSource(audio);
source.connect(audioCtx.destination);
audio.play();
