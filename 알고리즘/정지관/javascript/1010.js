const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().split("\n");

function factorial(n) {
  let result = 1;
  for (let i = 1; i <= n; i++) {
    result = result * i;
  }

  return result;
}

const size = parseInt(input[0]);
for (let i = 1; i <= size; i++) {
  let scan = input[i].split(" ");
  console.log(
    Math.round(
      Math.round(factorial(parseInt(scan[1])) / factorial(parseInt(scan[0]))) /
        factorial(parseInt(scan[1]) - parseInt(scan[0]))
    )
  );
}
