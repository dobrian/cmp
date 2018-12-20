# Envelope Follower

Output should always be positive.

## Mean
One can use the mean of a signal to follow the envelope. Essentially, a buffer is allocated and filled with samples from the signal after rectification. Then the average of the buffer is taken to be the envelope. Naturally, the larger the buffer the smoother the output but more delayed (in time) the result.

```
float EF::GetMean(float sample)
{
  // wrap the index pointer
  if(envelopePosition >= envelopeArraySize)
    envelopePosition = 0;
	if(envelopePosition < 0)
    envelopePosition = 0;

  // FIRST: rectify the input
	if(sample < 0.0)
		sample = -1.0 * sample;

  // SECOND: add to array to calculate mean
  envelopeArrayTotal = envelopeArrayTotal - envelopeArray[envelopePosition] + sample;
  envelopeArray[envelopePosition] = sample;
  envelopePosition++;

  // THIRD: mean is total/arraysize
  return(envelopeArrayTotal/(float)envelopeArraySize);
}
```

## RMS

```
float EF::GetRMS(float sample)
{
    long meansquare;
    float square;
    if(envelopePosition >= compRMSArraySize)
            envelopePosition = 0;

    // FIRST: square the new sample
    // square range 0.0 to 1.0
    square = sample * sample;

    // SECOND: add to array to calculate mean
    envelopeArrayTotal = envelopeArrayTotal - envelopeArray[envelopePosition] + square;
    envelopeArray[envelopePosition] = square;
    envelopePosition++;

	meansquare = envelopeArrayTotal/compRMSArraySize;
    // THIRD: meansquare needs to be scaled up to 65535 for root table lookup
//    meansquare = (long)(envelopeArrayTotal * 65536.0);
//	if(meansquare > 65535)
//		meansquare = 65535;
    // FOURTH: return the root of the mean of squares
    return(sqrt(meansquare));
}
```

## Attack-Release

```
float EF::GetPeakAttackRelase(float attack, float release, float sample)
{
	float attackMultiplier;
	float releaseMultiplier;
	
	if(sample < 0.0)
		sample = -sample;

	attackMultiplier = pow(0.01, 1.0/( attack * samplerate));
	releaseMultiplier = pow(0.01, 1.0/( release * samplerate));

	if(sample > peak)
		peak = attackMultiplier * (peak - sample) + sample;
	else
		peak = releaseMultiplier * (peak - sample) + sample;
	return(peak);
}
```

## Envelope Followers Compared

![Envelope Followers Compared](/ucsdResources/envelopes/images/envFollowersCompared.svg)

Note how the envelope followers with a larger buffer are smoother but delayed in time. Link to a larger version of the image is [here](/images/envFollowersCompared_large.svg)
