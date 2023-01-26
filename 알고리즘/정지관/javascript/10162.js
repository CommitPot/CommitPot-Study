let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString();
let number = parseInt(input);
let arr = [0, 0, 0];

if (number % 10 === 0) {
  arr[0] = Math.floor(number / 300);
  arr[1] = Math.floor((number - arr[0] * 300) / 60);
  arr[2] = Math.floor((number - arr[0] * 300 - arr[1] * 60) / 10);
} else {
  return console.log(-1);
}
console.log(arr.join(" "));
