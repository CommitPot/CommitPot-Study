let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().split("\n");
let size = parseInt(input[0]);
let arr = input[1].split(" ").map((number) => Number(number));
let num = 0;

for (let i = 0; i < size; i++) {
  if (arr[i] === 1) {
    num++;
  }
  for (let j = 2; j < arr[i]; j++) {
    if (arr[i] % j === 0) {
      num++;
      break;
    }
  }
}

console.log(size - num);
