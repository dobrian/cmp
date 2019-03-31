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