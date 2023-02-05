let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString();

let number = parseInt(input);
let total = 0;
let num = 0;
let arr = [64, 32, 16, 8, 4, 2, 1];

for (let i = 0; i < 7; i++) {
  if (number - total >= arr[i]) {
    total += arr[i];
    num += 1;
  }
}

console.log(num);
