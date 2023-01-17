const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString();

const size = parseInt(input);

for (let i = 1; i <= size; i++) {
  let answer = "";
  for (let j = 0; j < size - i; j++) {
    answer += " ";
  }
  for (let j = 0; j < i; j++) {
    answer += "*";
  }
  console.log(answer);
}
