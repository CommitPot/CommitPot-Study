let input = require("fs").readFileSync(0).toString().split("\n");

let a = +input[0].split(" ")[0];
let b = +input[0].split(" ")[1];
let c = +input[1];

let allMin = a * 60 + b + c;
let hour = parseInt(allMin / 60);
let Min = allMin % 60;

if (hour >= 24) hour -= 24;

console.log(hour, Min);
