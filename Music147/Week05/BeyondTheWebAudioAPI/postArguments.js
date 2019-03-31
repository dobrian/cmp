function msg_int() {
  post(arguments); // this is totally unhelpful
  post("\n");
  var s = ""
  for (var i = 0; i < arguments.length; i++) {
    s += arguments[i] + " ";
  }
  post(s); // this is much better
  post("\n");
}