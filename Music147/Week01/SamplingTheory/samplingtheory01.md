Sampling Theory
===

Discrete Samples of a Continuous Signal
---

You're probably aware that when you're watching a movie you're actually watching a series of still photographs. Conventionally, 24 snapshots&mdash;also known as frames&mdash;are captured per second, and those are later played back (displayed one after the other) at a constant rate of 24 frames per second, the same rate at which the snapshots were taken. That means that the photos are shot at a rate of one every 1/24 of a second&mdash;which is to say every 0.041667 seconds, or every 41.667 milliseconds.

We think of the real world as being continuous. We think of time as a continuous flow, within which the objects in the world move (or don't) and change (or don't). We, and the rest of the world, move constantly forward in time. We can recall the past only with our memory, or with some sort of capture-and-storage mechanism such as a camera. With a camera we can, in effect, freeze time, by capturing and storing one instant as a still image. With a movie camera, we take 24 snapshots per second, and we can then replay the past by showing those photos at the same rate. Thus, with a series of discrete images, we can simulate the continuous flow of time.

Digital recording of sound works in much the same way, although we need to take many more than 24 snapshots of the sound per second. We use a microphone to transduce sound energy into an electrical signal. The voltage of that signal changes analogously to (proportionally to) the changing air pressure of the sound wave. At regular intervals, a computer can measure that voltage and represent it as a number, and store that number in memory. For accurate representation of sound, we need to take many thousands of measurements per second. For example, a CD recording uses a rate of 44,100 samples per second. Later we can read through those numbers at the same rate, and convert them back to voltages to drive a loudspeaker.

For this audio capture process, a circuit called a [sample-and-hold][sample-and-hold] is used.

![Sample-and-hold Signal][sample-and-hold image]<br>
_The gray curve represents the continuously changing voltage of the input signal. The red indicates the discrete voltages that are sampled periodically and held constant until the next sample._

The sample-and-hold circuit periodically holds its input voltage constant, giving the computer time to measure the voltage and quantize it as a numerical value.

The result is an ordered file of numbers&mdash;in this case, 44,100 numbers per second of sound. Just as a movie shows us 24 still images per second, a digital recording reproduces 44,100 constant voltages per second. A filter circuit is used to smooth that signal, so that it effectively replicates the continuously changing voltage of the original sound signal.

---

## Digital Audio

The article ["Digital Audio"][digital audio] describes the digital audio sampling process, and introduces some of its important terminology and concepts. You should try to understand the meaning of the terms listed below. If you don’t understand the explanation of those terms in the article, do some research in additional resources to try to learn more about the things you don’t understand.

---

## Terminology

- simple harmonic motion
- fundamental (resonant) mode of vibration
- harmonics (overtones, partials)
- harmonic series
- spectrum
- amplitude envelope
- loudness, amplitude
- pitch
- frequency
- decibel
- analog-to-digital converter
- digital-to-analog, converter
- Nyquist theorem (Nyquist frequency)
- sampling rate
- aliasing/foldover
- quantization
- quantization precision
- signal-to-quantization noise ratio (SQNR)
- clipping

---

## Self-Quiz

What is the sampling rate of CD-quality audio?
<br>44,100 Hz

If the sampling rate is 48,000 Hz, what is the Nyquist frequency?
<br>24,000 Hz

What is the range of frequencies that humans can hear as a tone?
<br>20 Hz to 20,000 Hz

If an amplitude of 1 is used as the 0 dB reference, what amplitude is signified by -6 dB?
<br>0.5

What adjective describes a tone that consists of frequencies that are all whole number multiples of the same fundamental frequency?
<br>Harmonic

---

## Additional Resources

[Digital Audio][digital audio], Christopher Dobrian

[Computer Music: A Theoretical and Historical Approach][computer music], Phil Burk et al.

[sample-and-hold]: https://en.wikipedia.org/wiki/Sample_and_hold
[sample-and-hold image]: ./sample-and-hold.svg
[digital audio]: http://music.arts.uci.edu/dobrian/digitalaudio.htm
[computer music]: http://sites.music.columbia.edu/cmc/MusicAndComputers/
