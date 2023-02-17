let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().split("\n");

for (let i = 0; i < 3; i++) {
  let arr = input[i]
    .split(" ")
    .map((number) => Number(number))
    .filter((num) => num === 0);
  switch (arr.length) {
    case 0:
      console.log("E");
      break;
    case 1:
      console.log("A");
      break;
    case 2:
      console.log("B");
      break;
    case 3:
      console.log("C");
      break;
    case 4:
      console.log("D");
      break;
  }
}
