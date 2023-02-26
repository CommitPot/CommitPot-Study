let fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().split("\n");
let stack = [];
let sum = 0;

for (let i = 1; i <= parseInt(input[0]); i++) {
  if (input[i] === "0") {
    stack.pop();
  } else {
    stack.push(parseInt(input[i]));
  }
}

stack.map((a) => (sum += a));
console.log(sum);
