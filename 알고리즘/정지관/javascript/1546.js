let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().split("\n");
let arr = input[1].split(" ").map((number) => Number(number));
let max = 0;
let total = 0;

for (let i = 0; i < parseInt(input[0]); i++) {
  if (arr[i] > max) {
    max = arr[i];
  }
  total += arr[i];
}

console.log((total / (max * parseInt(input[0]))) * 100);
