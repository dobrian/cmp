// on any line, any text after the two slashes is just commentary and is ignored by the compiler 

// by default the js object is created with 1 inlet and 1 outlet
// if you want some number of inlets or outlets other than 1, you must say so
// to do that, you give commands to set the object's "inlets" and "outlets" properties
// (setting the inlets to 1 is technically unnecessary, since it's the default anyway)
// "=" does not mean "is equal to", it means set the thing on the left to the value on the right
// the semicolon signals that the command is complete

inlets = 1; // the default number of inlets and outlets is 1 anyway
outlets = 2; // this changes the number of outlets to 2

// the above lines are called "global" code
// they are run first, automatically when an instance of the  object is created

// whenever you want your object to do something in response to a message,
// that's called giving the object a "method" to do the task
// to create a method, type "function" and give the function a method name
// follow the method name immediately by two parentheses to show that it's the name of a function
// (the parentheses can contain "arguments" to the function, if they're needed)
// then create two curly braces to contain the things done by the function
// inside the curly braces you list the things you want done
// "bang" is a useful method name, of course, since it's a special Max message
// when the object receives the word "bang" it looks to see if it has a "bang" method
// if so, then it executes the "bang" function

function bang() { // whenever a bang is received (bang has no arguments)
    outlet(1, "bang"); // send out the right outlet first, for good Max behavior
    outlet(0, "bang");  // then send out the left outlet
}

// the "outlet" function is a method that's available in every js object
// it expects two arguments, separated by a comma:
// the first is the outlet number you're referring to, numbered left to right, starting at 0
// the second is the message you want to send out that outlet 

// "anything" is another special method name,
// that's designed for handling unpredicted messages
// (anything that's not explicitly specified as a method)

function anything() { // any message other than bang
    bang(); // run the bang function anyway
}

// in this case we want to treat every message as if it were "bang"