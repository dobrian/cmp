### Delay

You can create a delay effect with `audioCtx.createDelay()`.  Delays belong
after a sound-generation node, like an oscillator, buffer source, or input
stream, but before the dac.  Therefore, a basic delay setup may look like this:

	const audioCtx = new AudioContext();

	// create oscillator
	const oscillator = audioCtx.createOscillator();
	oscillator.frequency = 220;
	oscillator.type = "sawtooth";

	// create delay
	const delay = audioCtx.createDelay();
	delay.delayTime = 1;

	// connect nodes and start the sound
	oscillator.connect(delay);
	delay.connect(audioCtx.destination);

A `DelayNode` only has one property: the `delayTime`, which is in seconds.  At
the moment, we have implemented a feedforward delay, since we are not feeding
the delay line back into itself.  To implement a feedback delay, we need to add
a `GainNode` to lower the delay's volume—otherwise, we will generate feedback.

	const delay = audioCtx.createDelay();
	delay.delayTime = 1;
	const delayGain = audioCtx.createGain();
	delayGain.gain.value = 0.5;

	delay.connect(delayGain);
	delayGain.connect(delay);


### Reverb

### Distortion

### Dynamics Processing
