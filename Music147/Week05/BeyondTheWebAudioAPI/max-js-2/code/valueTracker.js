// toplevel `value` variable can be modified by all the functions below
var value = 0;

function bang() {
  outlet(0, value);
}

function msg_int(i) {
  value += i;
}

function msg_float(f) {
  value += f;
}

function set(f) {
  value = f;
}

function double() {
  value *= 2;
}

function halve() {
  value *= 0.5;
}