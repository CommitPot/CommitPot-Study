const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [N, M] = input[0].split(" ").map(Number);
const numList = input[1].split(" ").map(Number);
const ranges = input.slice(2);

const sumList = [0, numList[0]];
const answer = [];

for (let i = 1; i < N; i++) {
  sumList.push(numList[i] + sumList[i]);
}

for (let i = 0; i < M; i++) {
  const range = ranges[i].split(" ").map(Number);
  answer.push(sumList[range[1]] - sumList[range[0] - 1]);
}

console.log(answer.join("\n"));
