let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().split("\n");
let arr = input[1].split(" ").map((number) => Number(number));

arr.sort(function (a, b) {
  return a - b;
});

console.log(arr[0], arr[parseInt(input[0]) - 1]);
