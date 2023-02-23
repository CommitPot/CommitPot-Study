let fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().split("\n");
let queue = [];
let answer = [];

for (let i = 1; i <= parseInt(input[0]); i++) {
  let arr = input[i].split(" ");
  switch (arr[0]) {
    case "push":
      queue.push(arr[1]);
      break;
    case "pop":
      if (queue.length === 0) {
        answer.push(-1);
      } else {
        answer.push(queue.shift());
      }
      break;
    case "size":
      answer.push(queue.length);
      break;
    case "empty":
      if (queue.length === 0) {
        answer.push(1);
      } else {
        answer.push(0);
      }
      break;
    case "front":
      if (queue.length === 0) answer.push(-1);
      else answer.push(queue[0]);
      break;
    case "back":
      if (queue.length === 0) answer.push(-1);
      else answer.push(queue[queue.length - 1]);
      break;
  }
}

console.log(answer.join("\n"));
