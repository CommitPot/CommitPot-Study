let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().split("\n");

for (let i = 0; i < input.length - 1; i++) {
  let [a, b] = input[i].split(" ");
  console.log(Number(a) + Number(b));
}
