autowatch = 1;

outlets = 1;

var WINDOW_SIZE = 2000;
var BACKTRACK_SEARCH_SAMPLES = 100; // TODO: make dependent on sample rate
var ONSET_DIFFERENCE_VARIABILITY = 0.8;

var buffer = null;


function set(bufferName) {
  buffer = new Buffer(bufferName);
}


function bang() {
  // Scroll through all samples to look for the window that gives you the largest amplitude difference.
  var maximumDifference = 0;
  var maximumDifferenceFrameNumber = 0;
  for (var frameNumber = 0; frameNumber < buffer.framecount() - WINDOW_SIZE; frameNumber += 1) {
    var difference = findAmplitudeDifference(frameNumber);
    if (difference > maximumDifference) {
      maximumDifference = difference;
      maximumDifferenceFrameNumber = frameNumber;
    }
  }
  
  var onsetFrameNumber = maximumDifferenceFrameNumber;
  outlet(0, onsetFrameNumber);
}


function findAmplitudeDifference(frameNumber) {
  var currentAmplitude = Math.abs(buffer.peek(1, frameNumber));
  var futureAmplitude = Math.abs(buffer.peek(1, frameNumber + WINDOW_SIZE));
  return futureAmplitude - currentAmplitude;
}
