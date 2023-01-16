let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().split("\n");

let result = [];
const size = parseInt(input[0]);

for (let i = 1; i <= size; i++) {
  let scan = input[i].split(" ");
  let a = 1;
  for (let j = 0; j < scan[1]; j++) {
    a = (a * Number(scan[0])) % 10;
  }
  result[i] = a;
}

for (let i = 1; i <= size; i++) {
  console.log(result[i] === 0 ? 10 : result[i]);
}
