let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
let n = Number(input[0])
let max = 0;

input.shift()
input.pop()
input = input.map(Number).sort((a, b) => b - a)

for(let i = 0; i < n; i++) {
    let total;
    total = input[i] * (i+1)
    if(total > max) max = total;
}

console.log(max)
