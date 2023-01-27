let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString();
let number = parseInt(input);
let total = 0;

if (number !== 4 && number !== 7) {
  while (number > 0) {
    if (number >= 5) {
      number -= 5;
      total += 1;
    } else if (number >= 3) {
      number -= 3;
      total += 1;
    } else if (number === 1) {
      number -= 1;
      total += 1;
    } else if (number === 2) {
      number -= 2;
      total += 2;
    }
  }
} else {
  total = -1;
}
console.log(total);
