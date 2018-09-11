# Simple Lowpass Filter

---

## Introduction

A lowpass filter reduces the high-frequency content of a signal while allowing lower frequencies to pass through.

There are many reasons why one might want to attenuate or remove high frequencies. In the analog-to-digital conversion (ADC) process of digitizing an electrical signal, it's important to remove frequencies that are above the Nyquist frequency (i.e., that are above 1/2 the sampling rate) so that they wont be misrepresented in the digital signal. A lowpass filter used for that purpose is called an _anti-aliasing_ filter. In a digital signal received from a sensor (e.g., a motion detector), the data might be noisy and jittery or might contain occasional spurious incorrect values. A _smoothing_ lowpass filter can smooth out those inconsistencies. And in the case of an audio signal, a lowpass filter is often used to reduce high-frequency hiss in a recording, or to reduce the amplitude of upper frequencies in the sound itself, in order to change the sound's timbre.

In all cases, reducing high frequency content of a signal results in a slightly smoother-looking waveform in the time domain.

---

## The Simplest Lowpass Filter

Most lowpass filters smooth the input signal by taking a weighted combination of the current input sample and one or more previous samples, to calculate a weighted moving average. The simplest example of this would be a filter that outputs the average (mean) of the current input sample and the previous input sample. The difference equation for that lowpass filter would be:

_y<sub>n</sub> = (x<sub>n</sub>+x<sub>n-1</sub>)/2_

where _x<sub>n</sub>_ is the value of the current input sample, _x<sub>n-1</sub>_ is the previous input sample, and _y<sub>n</sub>_ is the current output sample.

This kind of averaging won't alter the input signal much at all if the signal is changing very gradually from one sample to the next, but it will smooth the signal considerably if the input changes drastically from sample to sample. Thus, high frequencies, which cause more rapid and radical change in the signal, get smoothed out a little, reducing the high-frequency energy.

In case that's not intuitively obvious to you, let's look at a couple of examples. If an input stream of numbers is 0. 0.1 0.2 0.4 0.5 0.3 0.1 0.&mdash;and we assume an initial _x<sub>n-1</sub>_ with a value of 0.&mdash;the output would be 0. 0.05 0.15 0.3 0.45 0.4 0.2 0.05, which has a progression and shape very similar to the input.

<img src="./smoothcurve.png"><br>
_A smooth input is only slightly smoothed by the lowpass filter_

Whereas, with a jagged input stream (containing high-frequency energy), a smoothing filter will have a more remarkable effect. With an input stream such as 0.8 0.7 -0.1 0.9 -0.9 0.1 -0.4 0.4, the output would be 0.4 0.75 0.3 0.4 0. -0.4 0.15 0., which is significantly different in shape and amplitude (especially of the jagged high-frequency edges) from the input.

<img src="./jaggedcurve.png"><br>
_A jagged input is more noticeably smoothed by the lowpass filter_

Similarly, in audio signals, a sound without much high-frequency energy, such as the 1000 Hz sine tone shown below, is not much affected by this simple lowpass filter.

<img src="./sinelpfiltered.png"><br>
_A 1KHz sine tone almost totally unaffected by the lowpass filter_

Whereas a noise signal will show a more significant change because of the attenuation of its high frequencies.

<img src="./noiselpfiltered.png"><br>
_A noisy input is changed more by the lowpass filter_

Below, you can see the gently sloping amplitude response of this lowpass filter shown as a graph of amplitude over frequency.

<img src="./simplestlowpassresponsecurve.png"><br>
_Effect of the lowpass filter y<sub>n</sub> = (x<sub>n</sub>+x<sub>n-1</sub>)/2_

---

## Adjustable Lowpass Filter

It's worth pointing out that the averaging filter described above is just one instance of a slightly more general filter that would allow any balance between the current input sample and the previous input sample. The averaging equation above could be restated equivalently as

_y<sub>n</sub> = 0.5x<sub>n</sub>+0.5x<sub>n-1</sub>_

and that's a particular case of the equation

_y<sub>n</sub> = ax<sub>n</sub>+(1-a))x<sub>n-1</sub>_

in which the current input value is multiplied by a coefficent _a_ and the previous input value is multiplied by _(1-a)_. When the value of the coefficient _a_ is 1, there will be no change to the input (the delayed input sample will be multiplied by 0), whereas when the value of the coefficient _a_ is 0.5, _1-a_ will also equal 0.5, yielding the average of the most recent two input samples. Any value of _a_ between 1 and 0 will provide a different weighting between the two samples.

(It's worth noting that the filter's effect becomes strongest as _a_ approaches 0.5. As _a_ goes below 0.5 toward 0, the filter's effect becomes weaker until, when _a_ = 0, the output is the same as the input, just delayed by one sample.)

Interestingly, if we change the + operator to a - operator in the above equation,

_y<sub>n</sub> = ax<sub>n</sub>-(1-a))x<sub>n-1</sub>_

or

_y<sub>n</sub> = ax<sub>n</sub>+(a-1))x<sub>n-1</sub>_

the filter becomes a highpass filter.

<img src="./simplesthighpassresponsecurve.png"><br>
_Effect of the highpass filter y<sub>n</sub> = (x<sub>n</sub>-x<sub>n-1</sub>)/2_
