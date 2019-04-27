outlets = 3;

function oddEven() {
  var odds = [];
  var evens = [];
  for (var i = 0; i < arguments.length; i++) {
	var element = Math.abs(arguments[i]);
    if (element % 2 === 1) {
	  odds.push(element);
    } else {
      evens.push(element);
	}
  }

  // Ensure good Max right-to-left ordering.
  outlet(1, evens);
  outlet(0, odds);
}

function isPrime() {
  var primes = [];
  var composites = [];
  for (var i = 0; i < arguments.length; i++) {
	var element = arguments[i];
	var isPrime = true;
	if (element <= 1) {
	  composites.push(element);
	  continue;
    }
	for (var j = 2; j < element; j++) {
	  if (element % j === 0) {
	    composites.push(element);
	    isPrime = false;
	    break;
      }
    }
    if (isPrime) {
	  primes.push(element);
	}
  }

  // Ensure good Max right-to-left ordering.
  outlet(1, composites);
  outlet(0, primes);
}

function meanMedianMode() {
  // Find the mean.
  var sum = 0;
  for (var i = 0; i < arguments.length; i++) {
    var element = arguments[i]
    sum += element;
  }
  var mean = sum / arguments.length;
  
  // Find mode, taking advantage of JavaScript array's auto-resizing.
  var elementCounts = [];
  for (var i = 0; i < arguments.length; i++) {
	var element = arguments[i];
    elementCounts[element] = elementCounts[element] ? elementCounts[element] + 1 : 1;
  }
  var mode = [];
  var modeCount = 0;
  for (var i = 0; i < elementCounts.length; i++) {
	var count = elementCounts[i];
	if (count === modeCount) {
	  mode.push(i);
	} else if (count > modeCount) {
	  mode = [i];
	  modeCount = count;
    }
  }

  // Rebuild a sorted array using elementCounts and the counting sort algorithm:
  // https://en.wikipedia.org/wiki/Counting_sort.  Then, use the sorted array
  // to find the median.
  var sorted = [];
  for (var i = 0; i < elementCounts.length; i += 1) {
    if (elementCounts[i]) {
	  for (var j = 0; j < elementCounts[i]; j++) {
        sorted.push(i);
      }
    }
  }
  var median;
  if (sorted.length % 2 === 0) {
    median = (sorted[sorted.length / 2 - 1] + sorted[sorted.length / 2]) / 2;
  } else {
	median = sorted[(sorted.length - 1) / 2];
  }

  // Ensure good Max right-to-left ordering.
  outlet(2, mode);
  outlet(1, median);
  outlet(0, mean);
}