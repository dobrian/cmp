# Clipping Methods

## What if the peak amplitude exceeds 1?
If the peak amplitude exceeds 1, the result is distortion of the signal in the form of clipping. This can damage certain hardware and is best avoided.

If the level above 1 is known, one can simply multiply the signal by 1 minus that value.

More likely, however, whether or not the amplitude will exceed 1 is unknown. In this case there are several options: hard clipping. soft clipping, limiters, or compressors.

#### Hard Clipping
Hard clipping is done by simply limited the maximum and minimum sample values. When a signal exceeds the limit, a hard edge is created that creates high frequency harmonics (distortion).


```
HardClip(float *block, float *output, long samplesPerBlock, float limit) {
  // iterate through the samples in the block
  for(sample = 0; sample<samplesPerBlock; sample++) {

    // check if it's greater
    if(block[sample] > limit) {
      *(output+sample) = limit;
    } else {
      *(output+sample) = block[sample];
    };

    // check if it's less
    if(block[sample] < (-1*limit)) {
      *(output+sample) = limit;
    } else {
      *(output+sample) = block[sample];
    };
  };
}
```
![Overlayed clipped sine and normal](/ucsdResources/envelopes/images/sine_clippedSine.svg)

In this image, the purple line is a sine that is unclipped with a maximum amplitude of 1. The green line is a sine that is clipped at -3 dB (approx. 0.707 linear amplitude). Notice the hard edge at the clipping limit.

#### Soft Clipping

Soft clipping is another method of clipping that softens the edges of the clipped boundary using non-linear functions. This can be done several ways; most often, however, you'll see the use of the tangent function or quadratic functions.

__Quadradic__

By calculating the coefficients beforehand, creating a soft clipper with the quadratic equation can be relatively fast. This method, however, does not allow scaling via a gain coefficient and thus acts to shield the output from being driven too hard.

$$
y = -0.5x^3 + 0x^2 + 1.5x + 0
$$

Simplified...

$$
y = -0.5x^3 + 1.5x
$$

```
QuadraticSoftClip(float *block, float *output, long samplesPerBlock, float limit) {
  int samplenumber = 0;
	float a = -0.5f;
	float b = 0.0;
	float c = 1.5f;
	float d = 0.0;
	float ingain;

  // iterate through the samples in the block
  for(sample = 0; sample<samplesPerBlock; sample++) {

    ingain = x->gain * *(in+sample); // get the input

    // if it's greater than 1, hard clip
    if(ingain > 1)
			*(out+sample) = 1.0f;
    // if it's less than -1, hardclip
		else if(ingain < -1)
			*(out+sample) = -1.0f;
    // else, do the softclipping
		else
			*(out+sample) = a * ingain * ingain * ingain
				+ b * ingain * ingain
				+ c * ingain
				+ d;
  };
}
```

Here is a plot of a sine wave run through this function when the input gain is 1 (0dB, purple) and 1.412 (+3dB, green). When this function is ran, you can see the distortion occur as the steepening of the angle as the waveform ascends and descends. Notice, however, that when the input gain is above unity, the function prevents it from going above 1.

![QuadraticSoftClip](/ucsdResources/envelopes/images/quadradicSoftClip.svg)

__Cubic__

$$
y = x - \bigg( \alpha \cdot x^3 \bigg )
$$

In this function, alpha is called the _scaling coefficient_ which can vary between `0` and the limit, typically 1/3 which produces a clipped level of about -3dB. When the scaling coefficient is 0, the waveform as it is is passed through (no clipping, no distortion) but as alpha is increased, the waveform is clipped (softly!).

![CubicSoftClip](/ucsdResources/envelopes/images/cubicSoftClip.svg)

INTERESTING THING TO ASSIGN??? <br/>
What happens when the scaling coefficient goes above approx. 1/3? Maybe have the students show it and describe what happens, especially harmonically...

__Tangent Function__

$$
y = \frac{2}{\pi} \text{ } arctan(\alpha \cdot x)
$$

![Arctangent Softclip](/ucsdResources/envelopes/images/atanSoftClip.svg)

Notice that when `alpha >> 10`, the function approaches infinite clipping distortion; i.e. approaches a square wave with soft edges.


__Thoughts__

Although both of these methods can produce soft clipping, the cubic or quadtradic functions are generally more efficient since trigonometric calculations must be performed on every sample in the tangent function.

By cascading multiple softclippers, one can crudely approximate analog distortion.

#### Limiter


#### Compressor
