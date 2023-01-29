let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().split("\n");
let [N, K] = input[0].split(" ").map((number) => Number(number));
let total = 0;

while (K !== 0) {
  if (input[N] <= K) {
    K -= input[N];
    total += 1;
  } else {
    N -= 1;
  }
}
console.log(total);
