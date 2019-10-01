# Ramp and Sawtooth

The ramp wave and a sawtooth wave are mirror images of one another. The ramp ascends linearly from -1 to +1 while the sawtooth descends linearly from +1 to -1. The methods here will produce a non-bandlimited waveforms.

## Ramp

A ramp wave is essentially a phasor that goes from -1 to +1.

$$
  x_{ramp}(t) = 2 \bigg( \frac{t}{p} \text{mod } 1 \bigg) - 1
$$

### Using algebra

Using the phasor as the starting point, it is fairly straightforward to create a ramp algebraically:

![Ramp Block Diagram](images/ramp_blockDiagram.png)

That is, take the phasor, multiply it by two and subtract one. This results in a ramp that ascends from -1 to +1. Or: `(phasor*2)-1`. This results in the following waveform, the first 512 samples of a 100Hz ramp at a samplerate of 8kHz:

![Ramp Wave](images/ramp.png)

### Listen
Notice that since this oscillator is not bandlimited one can hear the aliasing very clearly, especially when changing the frequency. [Click here to listen.](src/ramp/rampPlay.html)

## Sawtooth

A sawtooth wave is ramp that _descends_ from +1 to -1.

### Using algebra

Using the phasor as the starting point, it is fairly straightforward to create a ramp algebraically:

$$
  x_{sawtooth}(t) = -2 \bigg( \frac{t}{p} \text{mod } 1 \bigg) + 1
$$

![Ramp Block Diagram](images/sawtooth_blockDiagram.png)

That is, take the phasor, multiply it by two and subtract one. This results in a sawtooth wave that descends from +1 to -1. Or: `(phasor * -2) + 1`. This results in the following waveform, the first 512 samples of a 100Hz sawtooth at a samplerate of 8kHz:

![Ramp Wave](images/sawtooth.png)

### Listen
Notice that since this oscillator is not bandlimited one can hear the aliasing very clearly, especially when changing the frequency. It sounds identical to the ramp. [Click here to listen.](src/ramp/sawtoothPlay.html)
