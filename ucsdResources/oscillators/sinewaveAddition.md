# Addition using individual Sinewaves

In the same way we can populate a table to create a waveform, one can also generate and add the same sine tones individually and sum them in the output. The technique is to essentially calculate the relative amplitudes using the same formulas as before, put them in a table, and read from them during playback.

```
float fundamental = 440; // fundamental in Hz
int harms = 10; // number of harmonics
float sawtoothAmplitudeTable[harms]; // a table to keep the amplitudes in

// define a function to calculate the amplitudes
sawtoothAmp(int harm) {
  
}

// populate the table of amplitudes
for(i=1; i <= harms; i++) {
  *amplitudeTable[i] = sawtoothAmp(i);
}


// calculate a block


for(i=1; i <= harms; i++) {

}


```


Using this technique, one could also address the amplitude of each harmonic individually _after_ the waveform has been created. This could allow one to blend waveforms in time.
