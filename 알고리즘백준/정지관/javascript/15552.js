let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");

let result = "";
const size = parseInt(input[0]);

for (let i = 1; i <= size; i++) {
  let scan = input[i].split(" ");
  result += Number(scan[0]) + Number(scan[1]) + "\n";
}

console.log(result);
