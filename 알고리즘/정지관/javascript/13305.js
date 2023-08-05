let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().split('\n');
let line2 = input[1].split(' ').map(Number)
let line3 = input[2].split(' ').map(Number)
let min = line3[0]
let total = BigInt(0);

for(let i = 0; i < Number(input[0]) - 1; i++) {
    if(line3[i] < min) {
        min = line3[i]
    }
    total += BigInt(min) * BigInt(line2[i])
}
console.log(String(total))
