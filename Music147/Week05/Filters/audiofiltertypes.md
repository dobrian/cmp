# Audio Filter Types

---
## Demonstration Video

This video presents a few of the most common types of filter used for audio timbre transformation, shows how those filter types affect a sound, and explains a few important vocabulary terms like lowpass, highpass, bandpass, cutoff frequency, center frequency, resonance, bandwidth, and Q.

## Transcript

### Introduction

This is a brief demonstration of a few of the most common types of digital filter used for transforming the spectrum of an audio signal.

These two windows each contain a graph of amplitude over frequency, showing the possible range of frequencies from 0 Hz up to the Nyquist frequency of 22,050 Hz. The upper graph shows the spectrum-shaping effect of a digital filter, with the central horizontal line indicating no change in amplitude, and anything above or below that center line indicating that the filter will impart a boost or reduction in amplitude at a given frequency. The lower graph shows the approximate spectrum of the sound in real time, permitting us to see the change caused by the filter, as well as hear it.

### Lowpass filter

Probably the most commonly used filter for audio is the _lowpass_ filter. It has this name because it passes through the low frequencies and reduces the amplitude of the high frequencies. The most crucial parameter of a lowpass filter is the _cutoff frequency_, the frequency above which the content of the signal begins to be significantly attenuated. This filter is set to have a cutoff frequency of 10,000 Hz, which is very high. That means that the frequencies attenuated by this filter will only be in the very top octave of our hearing range. By changing the cutoff frequency, we can change effect of the filter.

Because white noise contains equal energy at all frequencies from 0 Hz to the Nyquist frequency, it's often used as a good test of a filter's effect. [Turns noise on.] Notice that if I raise the cutoff frequency to 20,000 Hz, we hear a slight increase in the hissiness of the sound in the very highest frequencies, but it's not an enormous change perceptually. Now let's change the cutoff to lower frequencies: 5,000, 2,000, 1,000, 500, 200 and 100. (Because we're less sensitive to very low frequencies, we have to turn up the volume a bit to hear this extremely lowpass-filtered noise.) Of course, this filter is not a brick wall that suddenly suppresses all energy above the cutoff frequency, so we still hear some energy above the cutoff, but the cutoff is a good guideline for what we can expect the filter's effect to be.

### Highpass filter

Now let's change the filter type to the opposite, a _highpass_ filter, which passes high frequencies and attenuates low frequencies. Since the cutoff is 100 Hz, we hear all the frequencies above that. A highpass filter is commonly used to filter out unwanted low rumbling noises, especially when the part of the signal we want to hear doesn't contain low frequencies itself, such as a violin, flute, or female voice. As we raise the cutoff frequency, the noise loses its full body and gets hissier.

### Filtering a harmonic tone

Now let's do that same thing to a sustained tone with a fundamental frequency of 440 Hz. We'll use a sawtooth waveform because it's rich in harmonics, somewhat like a violin tone. Notice how the tone is at first "bright" and "buzzy" because of the high-frequency energy, but the lowpass filter can make it sound less so, even making it sound somewhat dark and muffled. Of course, if we set the cutoff frequency very low, it will even attenuate the fundamental frequency. As a rule of thumb, a lowpass filter is used to make a sound darker or more muffled&mdash;less bright&mdash;or perhaps to remove some unwanted high-frequency noise in the signal. Now if we switch to a highpass filter, we'll hear all the frequencies again, but as we raise the cutoff frequency, the lowest partials of the tone are attenuated. The reduction in amplitude of the first partial doesn't radically change our perception of what the fundamental pitch is, but it does make the sound seem thinner, tinnier.

It probably goes without saying, but I'll mention it anyway: if a sound doesn't contain much energy at high frequencies to begin with, then a lowpass filter might not have much effect, unless we make the cutoff frequency sufficiently low. For example, a 440Hz sine tone is not much affected by our lowpass filter, until we lower the cutoff near to that frequency.

### Bandpass filter

A _bandpass_ filter is essentially a combination of a lowpass and a highpass, leaving only a chosen band of frequencies to pass through (called the _passband_). So, when we're talking about a bandpass filter, we change the term cutoff frequency to _center frequency_, in order to refer to the frequency at the center of the passband. The width of the band will determine how drastic the filter's effect is.

The term _bandwidth_ has a specific definition: it's the range of frequencies beyond which the sound is attenuated by at least 3 decibels. So, we might have, for example a bandpass filter with a center frequency of 1000 Hz, and a bandwidth of 500 Hz, which will leave a relatively narrow band of frequencies around 1000 Hz and will reduce the amplitude of frequencies outside the 500 Hz range.

Another term you will hear used frequently in reference to bandpass filters is the _Q_. That's short for the _quality factor_, but everyone just says "Q". The Q also has a very specific definition: it's the center frequency divided by the bandwidth. So, our filter with a center frequency of 1000 Hz and a bandwidth of 500 Hz has a Q value of 2. Or, if you know a filter's center frequency is 1000 Hz and it has a Q of 10, you can calculate its bandwidth is 100 Hz.

Q = F<sub>0</sub> / BW, thus BW = F<sub>0</sub> / Q

By sweeping a bandpass filter over white noise, you can get a good sense of what different frequency regions sound like. [Turn on noise, sweep the filter.] If you narrow the bandwidth considerably (by increasing the Q), you can even narrow the bandwidth of the noise to the point where everything but the center frequency is attenuated to much that the noise starts to have a recognizable pitch.

Depending on the coefficients used in the difference equation of a bandpass filter, the filter might have not only an attenuating effect on frequencies outside the passband, it might also have a _resonance_ effect on and around the center frequency. Thus, bandpass filters can change the timbre of a sound quite dramatically. [Switching to sawtooth wave.] When you apply a narrow bandpass filter to a harmonic tone like a sawtooth wave, you can emphasize particular harmonics of the tone.

---

### Filtering music

Now let's try applying these three filter types to a piece of recorded music. We'll start with a lowpass filter, but with its cutoff frequency set so high that it has almost no effect. Then we can experiment with the lowpass, highpass, and bandpass filters at different frequencies.

There are many types of audio filter, and we've seen three of the most common: lowpass, highpass, and bandpass. In a music production application, the user will often be presented a cascading series of highpass, bandpass, and lowpass filters with a helpful graphic interface that allows the user to control the cutoff or center frequency, the slope or Q, and the gain or attenuation of each filter. This process of applying filters to get exactly the desired timbre is called _equalization_, or _EQ_ for short. An equalizer allows a music producer to get exactly the sound that he or she wants, by adjusting a series of different filters.

---

## Vocabulary

- lowpass filter
- highpass filter
- cutoff frequency
- bandpass filter
- center frequency
- passband
- bandwidth
- Q (quality factor)
- resonance
- EQ (equalization)

---

## Self-quiz

Does a lowpass filter filter out low frequencies or high frequencies?<br>
Low frequencies

What exactly is meant by the bandwidth of a bandpass filter?<br>
It's the range of frequencies within which the attenuation effect is no greater than 3 dB, relative to the effect at the center frequency.

If you know the center frequency and the bandwidth of a filter, how would you calculate its Q?<br>
Q = F<sub>0</sub> / BW

How would you describe a lowpass filter's effect on the timbre of a sound?<br>
By reducing the higher frequencies, a lowpass filter often makes the sound seem darker and more muffled.

Why might you use a highpass filter when recording violin or female voice?<br>
To remove low-frequency rumbles such as from a ventilation fan, etc.
