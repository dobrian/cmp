# Music 147
Computer Audio and Music Programming
University of California, Irvine

## Introduction

The objective of this course is to provide computer programmers with a thorough understanding of sound and music—and of the digital representation of those phenomena—that will help them to program more effectively for sound and music applications.

## Topics

Fundamental knowledge of sound and music

Fundamental knowledge of programming in Max and JavaScript

Sampling theory and practicalities

Basics of sound file playback and control

Sound synthesis and performance control

The Musical Instrument Digital Interface (MIDI) protocol

Digital filters in theory and application

Audio effects processing, applications and implementations

Fourier transform and frequency-domain processing

Introduction to algorithmic composition

User interface design for musical applications

Software project design

## Week 1

### Physics of sound |Alex|

•  Harmonic series

•  Frequency and pitch

•  Amplitude (and intensity) and loudness

•  Noise

### Sampling theory |Chris|

•  Schematic description of ADC-DAC

•  PCM, sampling rate

•  Nyquist theorem, Nyquist frequency, aliasing

•  Bit precision, SQNR

•  Sound file formats

### Basics of music theory |Mark|

•  Note names

•  Equal-tempered tuning

•  Rhythm: beat, divisions (pulse), groupings, meter, tempo

•  Basics of Western notation

•  Absolute time and tempo-relative time

## Week 2

### Intro to Max and MSP

### Intro to JavaScript in HTML 5 |Mark|

### Linear mapping and linear interpolation |Alex|

### Basics of UI design for music |Alex|

## Week 3

### Keyboard and mouse input

• Providing input to JavaScript |Mark|

• Providing input to Max |Alex|

### RAM-based sample playback in Max

•  **buffer~** access and usage |Alex|

### Control signals

•  Classic waveforms as LFOs |Alex|

•  Vibrato and tremolo (of a synthesized tone)

•  Windows and envelopes (of a synthesized tone) |Alex|

### Sample processing in Max

•  Applying control signals to sample playback |Alex|

•  Windowing and granulation |Chris|

•  UI considerations for controlling processing |Alex|

### Sample recording and playback in the audio context of the Web Audio API |Mark|

•  Audio API context terminology and modules

•  Relating API implementations to Max implementations

•  Applying control signals to sample playback

•  Microphone input and recording to a buffer

## Week 4

### Building a synthesizer in Max

•  The concept (and limitations) of additive synthesis

•  Theory and implementation of basic FM synthesis

•  Common controls (keyboard, envelopes, modulations, pitchbend, lowpass filter, etc.)

•  Overview of other types of synthesis

### Building a synthesizer in Web Audio API |Mark|

•  Relating API implementations to Max implementations

•  Web MIDI API

### MIDI

•  The protocol, its pros and cons

•  Channel messages for performance

•  MIDI file format

## Week 5

### Digital filters in theory and practice |Chris|

•  Viewing sound in the spectral domain

•  Different audio filter types

•  The simplest lowpass filter

•  Improvements to the lowpass filter (balance between coefficients, use of feedback component)

•  FIR and IIR filters

•  The general causal filter difference equation

•  The biquad filter

•  The Z transform

•  Poles and zeros

•  The Z-domain transfer function

### Sample-level audio programming

•  **gen~**

•  Audio callback functions, overview and specifics

•  The Processor node in Web Audio API

•  [Programming MSP objects in C]

•  [Programming VST plug-ins]

## Week 6

### Delay, flanging, chorusing, reverberation, and other delay-based processing techniques

•  The musical uses of delay

•  Circular buffer, in theory and in practice

•  Delay in Max

•  Delay with feedback in Max

•  The comb filter

•  Variable delay, flanging

•  Variable delay, chorusing

### Dynamics processing

•  Amplitude-based event detection |Chris|

•  Thresholds and gating

•  Compression and limiting

### Distortion

•  Transfer functions and waveshaping

## Week 7

### Project design and planning: the software design process |Mark|

•  Standalone project in Max

•  Web-based audio/music app

•  OWL pedal plug-ins in **gen~**

•  [VST plug-in]

•  [Max for Live devices]

•  Other (iOS or Android app, etc.)

### Sound spatialization

•  Intensity-based stereo panning

•  Intensity-based multi-channel panning

•  Location-based Doppler effect

•  Ambisonics

•  Overview of other approaches (HRTF, WFS, MIAP, Atmos, etc.)

### Reverberation

•  Schroeder model

•  Feedback network model

•  IR convolution

### Implementing plug-ins in the OWL pedal

## Week 8

### Algorithmic composition |Mark|

•  Randomness and probability

•  Music-theoretic models

•  Mathematical models

•  Emergent systems

### Interactive computer music performance

•  Pitch and event tracking

•  Score following

•  Alternative controllers

### Sensor integration with Max

### OSC

### [MiraWeb]

### [Arduino]

## Week 9

### Applications of the Fourier Transform |Chris|

Principles and terminology

Implementation in Max with **pfft~**

Spectral filtering/processing

Cross-synthesis

Pitch tracking ( **sigmund~** )

### Student project development

## Week 10

### Student project refinement and completion

## Final

### Project presentations
