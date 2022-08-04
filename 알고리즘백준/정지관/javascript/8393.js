let input = require("fs").readFileSync(0).toString().trim();

let sum = 0;

for (let i = 1; i <= input; i++) {
  sum += i;
}
console.log(sum);
