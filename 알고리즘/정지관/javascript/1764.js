let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().split("\n");
let [N, M] = input[0].split(" ");
let result = [];
let i = 1;

const Nset = new Set();

for (i; i <= parseInt(N) + parseInt(M); i++) {
  if (i < parseInt(N) + 1) {
    Nset.add(input[i]);
  } else {
    if (Nset.has(input[i])) result.push(input[i]);
  }
}

console.log(result.length + "\n" + result.sort().join("\n"));
