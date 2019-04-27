outlets = 3;

function list(i, j, k) {
  // Since Max objects typically send out messages in right-to-left order,
  // it is good practice to follow that pattern in your JS objects.
  outlet(2, k);
  outlet(1, j);
  outlet(0, i);
}