let fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().split(" ");
let number = parseInt(input[0]) + parseInt(input[1]) + parseInt(input[2]);

console.log(number);
