# Square and Triangle

Two other simple waveforms, the square and triangle, can also be created with the phasor as input.

## Square

The square wave is just that: a waveform that resembles a square. It is a special case of the pulse wave, which we will see later, where the duty cycle (the ratio between the high and low points) is 50%. It can be created algebraically or via logic operations.

### Using algebra

_Caveat: this method resembled the engineering technique BFI more than a clean algebraic method._

One method of this is to create a ramp or sawtooth, multiply it by some very high number, and clip it at -1 and +1: `(ramp*9999999).clip(-1,1)`.

```
// make a clip function
float clip(float n, float lower, float upper) {
  if(n<lower) {
    return lower;
  } else if (n>upper) {
    return upper;
  } else {
    return n;
  }
}

void Osc::Square(float *frequency, float *output, long samplesPerBlock)
{
  long sample;
  float rampPhase;

  // calculate for each sample in a block
  for(sample = 0; sample<samplesPerBlock; sample++)
  {
    phaseIncrement = *(frequency + sample)/sampleRate; // get the phase increment for this sample
    rampPhase = (phase*2)-1; // make a ramp (-1 to +1)
    *(output+sample) = clip(ramp*9999999999, -1, 1); // get the output for this sample
    phase = phase + phaseIncrement; // increment the phase
  }
}
```

![Square from clipping](images/squareClip_blockDiagram.svg)

#### Counting samples

One can also count the number of samples in a period. That is, if we know our sample rate is 1000Hz and we want a square wave at a frequency of 50Hz, we know that a complete period of the square wave will be 1000/50 or `samplerate/frequency`. This means that a 50Hz square wave (or any waveform, for that matter) at a 1000Hz sample rate is going to have a period of 20 samples. Since we know that a square wave's duty cycle is 50%, we know that the wave will be +1 for 10 samples, then -1 for 10 samples.

__NOTE: This is related to BLIP and BLEP__

### Using logic

Perhaps a bit cleaner is to use logical operations on a phasor:

```
void Osc::Square(float *frequency, float *output, long samplesPerBlock)
{
  long sample;

  // calculate for each sample in a block
  for(sample = 0; sample<samplesPerBlock; sample++)
  {
    phaseIncrement = *(frequency + sample)/sampleRate; // get the phase increment for this sample
    // calculate the output for this sample
    if(phase <= 0) {
      *(output+sample) = -1;
    } else {
      *(output+sample) = 1;
    };
    phase = phase + phaseIncrement; // increment the phase
  }
}
```

### Combing a ramp and a sawtooth

One can also sum a ramp and a sawtooth, offset in phase by 1/2 of a cycle to create a square. We will see this method in the future when we use it to create pulses of different lengths in pulse width modulation.


```
float wrap(float in, float lower, float upper) {
  float val = 0;

  if BLAH BLAH
}

WRITE SUMMING THE TWO INTO A SQUARE
```

Whatever method is used, the result looks something like this:

![Square Wave](images/square.svg)

## Triangle

The triangle wave is another of the basic waveforms. It forms a triangle, centered about 0, that linearly ascends from -1 to +1, then from +1 to -1.

### Using algebra

If the input is a phasor, we can create a triangle wave using absolute value and some multiplication:

EQUATION HERE USING LATEX

`triangle = (abs(phasor-0.5)*4)-1;`
![Block Diagram](images/triangle1_blockDiagram.svg)

This method creates a triangle wave that begins it's cycle at the crest of the waveform. Here are the first 512 samples of a 100Hz triangle wave sampled at 8kHz.

![Triangle Wave](images/triangle.svg)

We can also use a slightly different method but using the floor function, or truncation, in addition to absolute value, where truncation removes the decimal portion of a floating point value (essentially rounding _down_ to the nearest integer).

EQUATION HERE

`triangle(f) = (4 * abs(phasor - trunc(phasor + 0.5))) - 1`
![Block Diagram](images/triangle2_blockDiagram.svg)

This method, as opposed to the one above, creates a triangle wave that begins its cycle at the trough:

![Triangle Wave](images/triangle_trough.svg)

When implemented either way, the result sounds like this:

FAUST HTML INTERACTIVE
