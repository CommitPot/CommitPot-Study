let fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString();
let number = parseInt(input);
let arr = [];

for (let i = 0; i < number / 4; i++) {
  arr.push("long");
}

console.log(arr.join(" "), "int");
