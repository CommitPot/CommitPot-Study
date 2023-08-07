let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().split('\n');

let n = Number(input[0])

let a = n.toString(2).split('').reverse().join('')

console.log(parseInt(a, 2))
