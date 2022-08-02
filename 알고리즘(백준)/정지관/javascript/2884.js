let input = require("fs").readFileSync(0).toString().split(" ");

let a = parseInt(input[0]);
let b = parseInt(input[1]);

if (b - 45 >= 0) b -= 45;
else {
  if (a - 1 < 0) {
    a = 23;
  } else {
    a -= 1;
  }
  b += 15;
}

console.log(a, b);
