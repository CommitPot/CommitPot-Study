let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().toLowerCase().split("\n");

let [a, b] = input[0].split(" ").map((number) => Number(number));
let num = input[1].split(" ");
let arr = [];

for (let i = 0; i < a; i++) {
  if (parseInt(num[i]) < b) arr.push(num[i]);
}

console.log(arr.join(" "));
