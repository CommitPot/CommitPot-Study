let fs = require("fs");
let input = fs
  .readFileSync("/dev/stdin")
  .toString()
  .split(" ")
  .map((number) => Number(number));
let max = 0;

for (let i = parseInt(input[1]); i >= 0; i--) {
  if (input[0] % i === 0 && input[1] % i === 0) {
    max = i;
    break;
  }
}

let min = (((input[0] / max) * input[1]) / max) * max;

console.log(max);
console.log(min);
