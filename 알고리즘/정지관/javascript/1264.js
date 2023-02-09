let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().toLowerCase().split("\n");
let i = 0;
let arr = new Array(input.length - 2).fill(0);

while (input[i] !== "#") {
  for (let j = 0; j < input[i].length; j++) {
    switch (input[i][j]) {
      case "a":
      case "e":
      case "i":
      case "o":
      case "u":
        arr[i] += 1;
    }
  }
  i++;
}
console.log(arr.join("\n"));
