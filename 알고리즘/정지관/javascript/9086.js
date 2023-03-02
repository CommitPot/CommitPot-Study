let fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().split("\n");
let number = parseInt(input[0]);
let arr = [];

for (let i = 1; i <= number; i++) {
  arr[i - 1] = input[i][0] + input[i][input[i].length - 1];
}

console.log(arr.join("\n"));
