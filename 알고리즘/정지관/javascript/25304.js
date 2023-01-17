const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().split("\n");

let result = 0;
const size = parseInt(input[1]);

for (let i = 2; i <= size + 1; i++) {
  let scan = input[i].split(" ");
  result += Number(scan[0]) * Number(scan[1]);
}

console.log(result === Number(input[0]) ? "Yes" : "No");
