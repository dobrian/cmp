outlets = 1;

var WINDOW_SIZE = 2000; // at a sample rate of 41000, this is about 50ms
var buffer = null;
if (jsarguments.length > 1) {
  buffer = new Buffer(jsarguments[1]);
}


// Change the buffer we're looking at.
function set(bufferName) {
  buffer = new Buffer(bufferName);
}


// This function compares the magnitudes (i.e. absolute value) of pairs of
// samples located 2000 samples apart.  The pairing with the biggest difference
// likely corresponds to a sound with a fast attack, aka a transient.
function bang() {
  var maximumDifference = 0;
  var maximumDifferenceSampleIndex = 0;

  // `buffer.framecount()` gives the total number of samples in a buffer
  for (var sampleIndex = 0; sampleIndex < buffer.framecount() - WINDOW_SIZE; sampleIndex += 1) {

    // `buffer.peek` gets the value of a sample at a given index (the first
    // argument is the channel, which is 1-indexed for some reason) 
    var currentMagnitude = Math.abs(buffer.peek(1, sampleIndex));
    var futureMagnitude = Math.abs(buffer.peek(1, sampleIndex + WINDOW_SIZE));
    var difference = futureMagnitude - currentMagnitude;
    if (difference > maximumDifference) {
      maximumDifference = difference;
      maximumDifferenceSampleIndex = sampleIndex;
    }
  }
  
  outlet(0, maximumDifferenceSampleIndex);
}
