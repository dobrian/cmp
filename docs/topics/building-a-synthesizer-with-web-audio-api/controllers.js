const audioCtx = new AudioContext();

const playMiddleC = () => {
  const oscillator = audioCtx.createOscillator();
  oscillator.frequency.value = 261.63;
  const oscillatorGain = audioCtx.createGain();
  oscillator.connect(oscillatorGain);
  oscillatorGain.connect(audioCtx.destination);
  oscillator.start();

  oscillatorGain.gain.setValueAtTime(0, audioCtx.currentTime);
  oscillatorGain.gain.linearRampToValueAtTime(1, audioCtx.currentTime + 0.1);
  oscillatorGain.gain.linearRampToValueAtTime(0, audioCtx.currentTime + 1);
  oscillator.stop(audioCtx.currentTime + 1); // remember to stop the oscillator in order
                                             // to trigger the garbage collector 
};

$(document).keydown((event) => {
  if (event.which === 67) {
    playMiddleC();
  }
});
