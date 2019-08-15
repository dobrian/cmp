// this object stores one number, either integer or float
// it emulates the behavior of the int and float objects in Max

inlets = 2; // this time we'll have two inlets
outlets = 1; // and one outlet

// this creates a global variable in this object
// in JavaScript, a variable can contain anything (not just numbers)

var x = 0; //  create a variable named "x" and set it to 0

// the next section is for handling any typed-in messages
// it uses the "if{}else{}" construct to test things
// and nests two other ifs within the first if

// jsarguments is a provided array containing the items typed in the object box after the "js"
// so jsarguments[0] is the filename, jsarguments[1] is the next thing, and so on
// the property jsarguments.length is the number of items in the array

if (jsarguments.length > 1) { // if there's something typed in besides just the filename
    if ( isNaN( jsarguments[1] ) ) { // check in case the argument after the filename is not a number
        post( "Error in js", jsarguments[0], ": argument must be a number" );
    } // if it's not a number, print an error message in the Max window
    else { // otherwise, 
        x = jsarguments[1]; // put it into the variable x to set its initial value
    } // and the next thing is just a courtesy warning to the user
    if (jsarguments.length > 2) { // if there are unneeded extra arguments,
        post( "Warning from js", jsarguments[0], ": there are extra arguments" );
    }  // report that in the Max window
}

function bang() { // bang will trigger output of the stored number
    if (inlet == 1) { // but if it comes in the 2nd inlet...
        post( "Error in js", jsarguments[0], ": second inlet does not understand bang" );
    } // do nothing except report the error
    else { // otherwise, it must be in the 1st inlet, so...
        outlet(0, x); // send out the stored number
    }
}

// when an int comes in an inlet, it calls the "msg_int" function
// the argument of the msg_int function is the value of the number that came in

function msg_int( incoming ) { // we arbitrarily gave the name "incoming" to the argument
    x = incoming; // whatever it is, put it in the variable x
    if (inlet == 0)  { // and if it came in the left inlet.
        outlet(0, x); // send it out
    }
}

function msg_float( incoming ) { // if a float comes in
    msg_int(incoming);  // do the same thing as for msg_int
}

function set( incoming ) { // another way to set the value without causing output
    if (inlet == 1) { //  if it comes in the 2nd inlet...
        post( "Error in js", jsarguments[0], ": second inlet does not understand set" );
    } // do nothing except report the error
    else { // otherwise, it must be in the 1st inlet, so...
        if ( isNaN( incoming ) ) { // make sure its argument is not a word instead of a number
            post( "Error in js", jsarguments[0], ": argument for the set message must be a number" );
        }
        else { // if it's been verified as a number, store it
            x = incoming;
        }
    }
}

function send( receiver ) { // send the value to a named object
    if (inlet == 1) { //  if it comes in the 2nd inlet...
        post( "Error in js", jsarguments[0], ": second inlet does not understand send" );
    } // do nothing except report the error
    else { // otherwise, it must be in the 1st inlet, so...
        messnamed( receiver, x ); // this sends the contents of x to the named receive object(s)
    }
}