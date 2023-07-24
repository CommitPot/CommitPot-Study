let fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().split('\n');
let first = input[0].split(' ').map((res) => parseInt(res))
let second = input[1].split(' ').map((res) => parseInt(res))

second.sort((a, b) => a -b)
console.log(second[first[1]-1]);
