const audioCtx = new AudioContext();

// Create an oscillator.
const oscillator = audioCtx.createOscillator();
oscillator.frequency.value = 220;
oscillator.type = "sawtooth";
oscillatorGain = audioCtx.createGain();
oscillatorGain.gain.setValueAtTime(0, audioCtx.currentTime); // start from silence!
oscillator.connect(oscillatorGain);
oscillatorGain.connect(audioCtx.destination);

oscillator.start();


// Create attack and release functions.
const attack = (attackTime, decayTime, sustainValue) => {
  oscillatorGain.gain.setValueAtTime(0, audioCtx.currentTime);
  oscillatorGain.gain.linearRampToValueAtTime(1,
                                              audioCtx.currentTime + attackTime);
  oscillatorGain.gain.linearRampToValueAtTime(sustainValue,
                                              audioCtx.currentTime + attackTime + decayTime);
};

const release = (releaseTime) => {
  oscillatorGain.gain.linearRampToValueAtTime(0,
                                              audioCtx.currentTime + releaseTime);
};


// Tie attack and release functions to "start" and "stop" buttons.
$("#start").on("click", () => {
  const attackTime = Number($("#attack").val());
  const decayTime = Number($("#decay").val());
  const sustainValue = Number($("#sustain").val());
  attack(attackTime, decayTime, sustainValue);
});

$("#stop").on("click", () => {
  const releaseTime = Number($("#release").val());
  release(releaseTime);
});


// Handle slider UI.
$("#attack").on("change", () => {
  $("#attack-indicator").text($("#attack").val() + " (seconds)");
});
$("#decay").on("change", () => {
  $("#decay-indicator").text($("#decay").val() + " (seconds)");
});
$("#sustain").on("change", () => {
  $("#sustain-indicator").text($("#sustain").val() + " (gain)");
});
$("#release").on("change", () => {
  $("#release-indicator").text($("#release").val() + " (seconds)");
});
$("#attack-indicator").text($("#attack").val() + " (seconds)");
$("#decay-indicator").text($("#decay").val() + " (seconds)");
$("#sustain-indicator").text($("#sustain").val() + " (gain)");
$("#release-indicator").text($("#release").val() + " (seconds)");
