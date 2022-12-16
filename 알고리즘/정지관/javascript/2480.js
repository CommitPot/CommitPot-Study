let input = require("fs").readFileSync(0).toString().split(" ");

let a = parseInt(input[0]);
let b = parseInt(input[1]);
let c = parseInt(input[2]);

let res = 0;

if (a == b && b == c) {
  res = 10000 + 1000 * a;
} else if (a == b) {
  res = 1000 + 100 * a;
} else if (b == c) {
  res = 1000 + 100 * b;
} else if (c == a) {
  res = 1000 + 100 * a;
} else {
  res = Math.max(a, b, c) * 100;
}

console.log(res);
