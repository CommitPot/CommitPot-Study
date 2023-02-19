let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().split("\n");
let arr1 = input[0].split(" ").map((number) => Number(number));
let arr2 = input[1].split(",").map((number) => Number(number));

for (let j = 0; j < arr1[1]; j++) {
  for (let i = 0; i < arr2.length - 1; i++) {
    arr2[i] = arr2[i + 1] - arr2[i];
  }
  arr2.pop();
}

console.log(arr2.join(","));
