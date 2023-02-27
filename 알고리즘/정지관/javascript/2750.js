let fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().split("\n");
let arr = [];
for (let i = 1; i <= parseInt(input[0]); i++) {
  arr.push(parseInt(input[i]));
}
arr.sort((a, b) => {
  return a - b;
});

console.log(arr.join("\n"));
