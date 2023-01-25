let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().split("\n");

const size = parseInt(input[0]);
let total = 0;

let A = input[1].split(" ").map((number) => Number(number));
let B = input[2].split(" ").map((number) => Number(number));

A.sort(function (a, b) {
  return a - b;
});
B.sort(function (a, b) {
  return b - a;
});

for (let i = 0; i < size; i++) {
  total += A[i] * B[i];
}
console.log(total);
