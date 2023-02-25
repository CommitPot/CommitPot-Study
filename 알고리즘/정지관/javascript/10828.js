let fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().split("\n");
let stack = [];
let answer = [];

for (let i = 1; i <= parseInt(input[0]); i++) {
  let arr = input[i].split(" ");
  switch (arr[0]) {
    case "push":
      stack.push(arr[1]);
      break;
    case "pop":
      if (stack.length === 0) answer.push(-1);
      else answer.push(stack.pop());
      break;
    case "size":
      answer.push(stack.length);
      break;
    case "empty":
      if (stack.length === 0) {
        answer.push(1);
      } else {
        answer.push(0);
      }
      break;
    case "top":
      if (stack.length === 0) answer.push(-1);
      else answer.push(stack[stack.length - 1]);
      break;
  }
}

console.log(answer.join("\n"));
