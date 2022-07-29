let input = require("fs").readFileSync("/dev/stdin").toString().split(" ");

let a = parseInt(input[0]);
let b = parseInt(input[1]);

console.log(a - b);
