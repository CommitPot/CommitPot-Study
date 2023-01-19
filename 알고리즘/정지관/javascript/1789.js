let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString();

let total = 0;
let real;
let i;
for (i = 2; total < parseInt(input); i++) {
  total += i;
}

console.log(i - 2);
