const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().split("\n");

const size = parseInt(input[0]);

for (let i = 1; i <= size; i++) {
  let result = 0;
  let scan = input[i].split(" ");
  result = Number(scan[0]) + Number(scan[1]);
  console.log(`Case #${i}: ${result}`);
}
