let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().split("\n");
let order = parseInt(input[0]);
let arr = input[1].split(" ").map((number) => Number(number));
let total = 0;

arr.sort((a, b) => {
  return a - b;
});

for (let i = order; i > 0; i--) {
  total += arr[order - i] * i;
}
console.log(total);
