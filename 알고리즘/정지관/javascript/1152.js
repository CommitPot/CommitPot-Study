let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().split("\n");
let arr = input[0].split(" ").filter((word) => word !== "");

console.log(arr.length);
