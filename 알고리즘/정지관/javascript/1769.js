let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString();

let result = input;
let total = 0;
let progress = 0;

while (result.length !== 1) {
  if (Number(result) < 10) break;
  for (let i = 0; i < result.length; i++) {
    total += Number(result[i]);
  }
  progress++;
  result = total.toString();
  total = 0;
}

console.log(progress);
console.log(result % 3 === 0 ? "YES" : "NO");
