# Sinewave Addition in Tables

One can also add sine waves together (additive synthesis) to approximate the basic forms presented earlier in this section. Individual sine waves of appropriate frequencies and amplitudes (with matching phases) can be used or one can use a lookup method and fill the table with the sum of the waves. The latter method is shown here.

## Sawtooth and Ramp

The sawtooth has perhaps the most simple formula: given a harmonic series of sine waves, multiply each by the reciprocal of their harmonic number and sum. For instance, the first harmonic is multiplied by 1/1, the second harmonic, is multiplied by 1/2, the third harmonic is multiplied by 1/3, and so on. In other words:

$$
  x_{saw}(t) = \sum_{i=1}^{k} \frac{1}{k} sin(2\pi fkt)
$$

where _k_ is the number of harmonics and _sin(2πfkt)_ is a sine wave.

```
float table[1024];
int harmonics = 10; // 10 harmonics
float amp = 1.0; // amplitude
float max = 0; // for normalization

// FILL THE TABLE WITH ZEROS?? OR START WITH FILLING IT WITH THE FIRST HARMONIC??

// fill the table
for(k=1; k <= harmonics; k++) {
  // for each harmonic, go through and add it to the table
  for(i=0; i < tableSize; i++) {
    float samp;
    samp = (i*k)/tableSize; // get the increment
    samp = samp * 2PI; // scale the frequency
    table[i] = table[i] + (sin(samp) * 1/harmonic); // add it
    if (table[i] > max) {
      max = table[i]; // remember it if it's the largest value we've encountered
    }
  };
};

// normalize
for(i=0; i < tableSize; i++) {
  table[i] = table[i]/max; // scale
};

```

PUT AN ANIMATION HERE??? OR AT LEAST A PLOT OF THE APPOXIMATION

The ramp is created by simply inverting the phase of the sine wave used in the sawtooth:

$$
  x_{ramp}(t) = \sum_{i=1}^{k} \frac{-1}{k} sin(2\pi fkt)
$$

## Square

The square wave is created in much the same way as the sawtooth but using only the odd-numbered harmonics:

$$
  x_{square}(t) = \sum_{i=1}^{2k+1} \frac{1}{k} sin(2\pi fkt)
$$

```
float table[1024];
int harmonics = 10; // 10 harmonics
float amp = 1.0; // amplitude
float max = 0; // for normalization

// FILL THE TABLE WITH ZEROS?? OR START WITH FILLING IT WITH THE FIRST HARMONIC??

// fill the table
for(k=1; k <= harmonics; k++) {
  // if the harmonic is odd, go through and add it to the table
  if (k & 1 == 1) {
    for(i=0; i < tableSize; i++) {
      float samp;
      samp = (i*k)/tableSize; // get the increment
      samp = samp * 2PI; // scale the frequency
      table[i] = table[i] + (sin(samp) * 1/harmonic); // add it
      if (table[i] > max) {
        max = table[i]; // remember it if it's the largest value we've encountered
      };
    };
  };
};

// normalize
for(i=0; i < tableSize; i++) {
  table[i] = table[i]/max; // scale
};

```

## Triangle

The triangle wave, like the square wave, uses only odd harmonics but every other odd harmonics phase is inverted (multiplied by -1 or phase change by PI). The amplitude of the harmonics, however, is the reciprocal of the square of their mode number. This means that the first harmonic is multiplied by 1/1<sup>2</sup>, the third harmonic is multiplied by 1/3<sup>2</sup>, the fifth by 1/5<sup>2</sup>, etc.

$$
  x_{triangle}(t) = \sum_{i=1}^{k} (-1)^{i} n^{-2} (\text{sin}[nt])
$$

```
float table[1024];
int harmonics = 10; // 10 harmonics
float amp = 1.0; // amplitude
float max = 0; // for normalization

// FILL THE TABLE WITH ZEROS?? OR START WITH FILLING IT WITH THE FIRST HARMONIC??

// fill the table
for(k=1; k <= harmonics; k++) {
  // if the harmonic is odd, go through and add it to the table
  if (k & 1 == 1) {
    for(i=0; i < tableSize; i++) {
      float samp;
      samp = (i*k)/tableSize; // get the increment

      // invert the phase here!
      samp = samp * 2PI; // scale the frequency


      table[i] = table[i] + (sin(samp) * 1/(harmonic**2)); // add it
      if (table[i] > max) {
        max = table[i]; // remember it if it's the largest value we've encountered
      };
    };
  };
};

// normalize
for(i=0; i < tableSize; i++) {
  table[i] = table[i]/max; // scale
};

```
