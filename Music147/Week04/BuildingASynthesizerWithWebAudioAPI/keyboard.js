const audioCtx = new AudioContext();


const playMiddleC = () => {
  const oscillator = audioCtx.createOscillator();
  oscillator.frequency.value = 261.63;
  oscillator.type = "square";
  const oscillatorGain = audioCtx.createGain();
  
  oscillator.connect(oscillatorGain);
  oscillatorGain.connect(audioCtx.destination);
  
  oscillator.start();

  // Create an envelope
  oscillatorGain.gain.setValueAtTime(0, audioCtx.currentTime);
  oscillatorGain.gain.linearRampToValueAtTime(1, audioCtx.currentTime + 0.1);
  oscillatorGain.gain.linearRampToValueAtTime(0, audioCtx.currentTime + 0.9);
  oscillator.stop(audioCtx.currentTime + 1);
};

$(document).keydown((event) => {
  console.log(event.which);
  if (event.which === 67) {
    console.log("fadein");
    playMiddleC();
  }
});
