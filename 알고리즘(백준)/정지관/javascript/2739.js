let input = require("fs").readFileSync(0).toString().trim();
let val = parseInt(input);

for (let i = 1; i < 10; i++) {
  console.log(`${val} * ${i} = ${val * i}`);
}
