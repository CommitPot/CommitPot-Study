let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString();
let number = parseInt(input);

let dp = [];

dp[1] = 1;
dp[2] = 0;
dp[3] = 1;
dp[4] = 1;
dp[5] = 1;

for (let i = 6; i <= number; i++) {
  dp[i] = 0;
  if (dp[i - 1] === 0 || dp[i - 3] === 0 || dp[i - 4] === 0) dp[i] = 1;
}

if (dp[number] == 1) console.log("SK");
else console.log("CY");
