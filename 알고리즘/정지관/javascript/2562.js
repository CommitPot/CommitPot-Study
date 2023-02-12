let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().split("\n");
let max = 0;
let num = 0;

for (let i = 0; i < input.length; i++) {
  if (parseInt(input[i]) > max) {
    max = parseInt(input[i]);
    num = i;
  }
}

console.log(max);
console.log(num + 1);
