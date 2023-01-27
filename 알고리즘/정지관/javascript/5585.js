let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString();
let leftMoney = 1000 - parseInt(input);
let total = 0;

while (leftMoney > 0) {
  if (leftMoney >= 500) {
    leftMoney -= 500;
    total += 1;
  } else if (leftMoney >= 100) {
    leftMoney -= 100;
    total += 1;
  } else if (leftMoney >= 50) {
    leftMoney -= 50;
    total += 1;
  } else if (leftMoney >= 10) {
    leftMoney -= 10;
    total += 1;
  } else if (leftMoney >= 5) {
    leftMoney -= 5;
    total += 1;
  } else if (leftMoney >= 1) {
    leftMoney -= 1;
    total += 1;
  }
}
console.log(total);
