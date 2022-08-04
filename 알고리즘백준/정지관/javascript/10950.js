let input = require("fs").readFileSync(0).toString().split("\n");

for (let i = 1; i <= input[0]; i++) {
  let scan = input[i].split(" ");
  console.log(Number(scan[0]) + Number(scan[1]));
}
