let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString();

let count = 0;
let result;

if (parseInt(input) < 10) input = "0".concat(input[0]);
result = Number(input[1]) * 10 + ((Number(input[1]) + Number(input[0])) % 10);
while (parseInt(input) !== result) {
  result = (result % 10) * 10 + (((result % 10) + parseInt(result / 10)) % 10);
  count++;
}
console.log(count + 1);
