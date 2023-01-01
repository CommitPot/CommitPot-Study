const fs = require("fs");
const input = fs
  .readFileSync("/dev/stdin")
  .toString()
  .split(" ")
  .map((value) => +value);

const chess = [1, 1, 2, 2, 2, 8];
const result = input.map((value, index) => {
  return chess[index] - value;
});

console.log(...result);
