let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().split('\n');

let n = Number(input[0])

pibo = [];
pibo.push(0);
pibo.push(1);
while (pibo[pibo.length - 1] < 1e9) pibo.push(pibo[pibo.length - 2] + pibo[pibo.length - 1]);


for(let i = 1; i <= n; i++) {
    let now = Number(input[i])
    let j = pibo.length - 1;
    let result = [];
    while(now > 0) {
        if(now >= pibo[j]) {
            now -= pibo[j];
            result.push(pibo[j])
        }
        j--;
    }
    console.log(result.reverse().join(' '))
}
