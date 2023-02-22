let fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().split("\n");
let word = "";
let arr = [];
let i = 0;

for (let k = 0; k < input.length - 1; k++) {
  arr[k] = input[k].length;
}

for (let j = 0; j < Math.max(...arr); j++) {
  for (i = 0; i < input.length - 1; i++) {
    if (input[i][j]) {
      word += input[i][j];
    }
  }
}

console.log(word);
