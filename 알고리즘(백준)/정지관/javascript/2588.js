let input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let a = parseInt(input[0]);
let b = input[1];

console.log(a * b[2]);
console.log(a * b[1]);
console.log(a * b[0]);
console.log(a * b);
