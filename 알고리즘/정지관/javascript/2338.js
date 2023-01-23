const fs = require("fs");

const input = fs.readFileSync("/dev/stdin").toString().split("\n").map(BigInt);

let answer = input[0] + input[1] + "\n";
answer += input[0] - input[1] + "\n";
answer += input[0] * input[1];

console.log(answer);
