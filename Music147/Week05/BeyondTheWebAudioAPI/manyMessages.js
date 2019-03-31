outlets = 3;

function oddEven() {
  for (var i = 0; i < arguments.length; i++) {
	var element = Math.abs(arguments[i]);
    if (element % 2 === 1) {
	  outlet(0, element);
    } else {
      outlet(1, element);
	}
  }
}

function isPrime() {
  for (var i = 0; i < arguments.length; i++) {
	var element = arguments[i];
	var isPrime = true;
	if (element <= 1) {
	  outlet(1, element);
	  continue;
    }
	for (var j = 2; j < element; j++) {
	  if (element % j === 0) {
	    outlet(1, element);
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
  var sum = 0;
  for (var i = 0; i < arguments.length; i++) {
    var element = arguments[i]
    sum += element;
  }

}