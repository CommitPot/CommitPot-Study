let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().split("\n");
let i = 0;

while (1) {
  let [a, b] = input[i].split(" ");
  if (Number(a) === Number(b) && Number(a) === 0) break;
  console.log(Number(a) + Number(b));
  i++;
}
