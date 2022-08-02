let input = require("fs").readFileSync(0).toString().trim().split("\n");

let a = Number(input[0]);
let b = Number(input[1]);

if (a > 0 && b > 0) console.log("1");
if (a < 0 && b > 0) console.log("2");
if (a < 0 && b < 0) console.log("3");
if (a > 0 && b < 0) console.log("4");
