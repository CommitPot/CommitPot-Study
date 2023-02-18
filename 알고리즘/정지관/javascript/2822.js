let fs = require("fs");
let input = fs
  .readFileSync("/dev/stdin")
  .toString()
  .split("\n")
  .map((number) => Number(number));
let arr = [];
let total = 0;

for (let i = 0; i < 5; i++) {
  let max = 0;
  for (let j = 0; j < 8; j++) {
    if (input[j] > input[max]) {
      max = j;
    }
  }
  arr.push(max + 1);
  total += Number(input[max]);
  input[max] = 0;
}

console.log(total);
console.log(
  arr
    .sort((a, b) => {
      return a - b;
    })
    .join(" ")
);
