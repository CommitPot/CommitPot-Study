let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString();

let num = Number(input);
let result = 0;

for (let i = 1; i <= num; i++) {
  let total = i;
  let string = i.toString();
  for (let j = 0; j < string.length; j++) {
    total += Number(string[j]);
  }
  if (total === num) {
    result = string;
    break;
  }
}

console.log(result);
