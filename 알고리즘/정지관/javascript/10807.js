let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().split("\n");

let size = parseInt(input[0]);
let arr = input[1].split(" ").map((number) => Number(number));
let total = 0;

for (let i = 0; i < size; i++) {
  if (arr[i] === parseInt(input[2])) total += 1;
}

console.log(total);
