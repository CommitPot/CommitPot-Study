let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString();
let arr = [];

for (let i = 0; i < input.length - 1; i++) {
  arr[i] = input[i];
}

arr.sort(function (a, b) {
  return b - a;
});

console.log(arr.join(""));
