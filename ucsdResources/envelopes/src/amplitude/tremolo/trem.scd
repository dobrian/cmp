var trem, size, sound, sr, freq;

sr = 44100; // samplerate

trem = ();
trem.freq = 2;

sound = ();
sound.sf = SoundFile.openRead("/home/roger/Documents/jacob/jobs/cmp/ucsdResources/envelopes/src/amplitude/tremolo/chord.wav");
sound.sig = FloatArray.newClear(sound.sf.numFrames);
sound.sf.readData(sound.sig);
// sound.sig.plot;

trem.sineInput = 20.collect{Signal.sineFill(sr/trem.freq, [1], [0])}.flat[0..sound.sf.numFrames];
// trem.sig.plot;

trem.makeTremSig = {|dict, tremSig, depth = 1|
	tremSig = (tremSig*0.5)+0.5;
	1 - (depth*tremSig);
};

trem.sig = trem.makeTremSig(trem.sineInput, 0.5);
// trem.sig.plot(findSpecs: false, minVal: 0);

sound.output = sound.sig.collect{|samp, i|
	samp * trem.sig[i];
}.asFloatArray;
// [sound.sig, trem.sig, sound.output].plot;

sound.sf.numFrames.postln;
// sound.sf.close;

// // write the sound
// f = File.open("/home/roger/Documents/jacob/jobs/cmp/ucsdResources/envelopes/src/amplitude/tremolo/chord.dat", "w");
// sound.sig.do{|val| f.write(val.asString++"\n")};
// f.close;
//
// // write the sound
// f = File.open("/home/roger/Documents/jacob/jobs/cmp/ucsdResources/envelopes/src/amplitude/tremolo/trem.dat", "w");
// trem.sig.do{|val| f.write(val.asString++"\n")};
// f.close;
//
// // write the sound
// f = File.open("/home/roger/Documents/jacob/jobs/cmp/ucsdResources/envelopes/src/amplitude/tremolo/chord_trem.dat", "w");
// sound.output.do{|val| f.write(val.asString++"\n")};
// f.close;



// a = SoundFile.new;
// a = SoundFile.openWrite("/home/roger/Documents/jacob/jobs/cmp/ucsdResources/envelopes/src/amplitude/tremolo/chord_trem.wav", "WAV");
// a.writeData(sound.output);
// a.close;
