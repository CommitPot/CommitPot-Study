let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString();
let number = Number(input);

console.log(number % 2 === 1 ? "SK" : "CY");
