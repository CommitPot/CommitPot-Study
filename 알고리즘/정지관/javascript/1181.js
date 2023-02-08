let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().split("\n");

let size = parseInt(input[0]);
let arr = [];

function isSame(element, i) {
  if (element !== arr) {
    return true;
  }
}

for (let i = 1; i <= size; i++) {
  if (!arr.includes(input[i])) arr.push(input[i]);
}

arr.sort();
arr.sort(function (a, b) {
  return a.length - b.length;
});

console.log(arr.join("\n"));
