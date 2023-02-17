let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString();
let arr = new Array(9).fill(0);
let max = 0;

for (let i = 0; i < input.length - 1; i++) {
  if (Number(input[i]) !== 9) {
    arr[Number(input[i])] += 1;
  } else {
    arr[6] += 1;
  }
}
arr[6] = Math.ceil(arr[6] / 2);

arr.sort(function (a, b) {
  return a - b;
});
console.log(arr[8]);
