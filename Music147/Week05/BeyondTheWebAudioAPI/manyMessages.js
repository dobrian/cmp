outlets = 3;

function oddEven() {
  for (var i = 0; i < arguments.length; i++) {
	var value = Math.abs(arguments[i]);
    if (value % 2 === 1) {
	  outlet(0, value);
    } else {
      outlet(1, value);
	}
  }
}

function isPrime() {
  for (var i = 0; i < arguments.length; i++) {
	var value = arguments[i];
	var isPrime = true;
	if (value <= 1) {
	  outlet(1, value);
	  continue;
    }
	for (var j = 2; j < value; j++) {
	  if (value % j === 0) {
	    outlet(1, value);
	    isPrime = false;
	    break;
      }
    }
    if (isPrime) {
	  outlet(0, value);
	}
  }
}

function meanMedianMode() {
  var mean = 0;
}