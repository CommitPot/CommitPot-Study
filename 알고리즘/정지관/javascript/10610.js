let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().split('\n');

let n = input[0]
let total = 0;

let result = n.split('').sort((a, b) => Number(b) - Number(a) ).join('')
result.split('').filter(res => res !== 0).map((res) => total += Number(res))

if(total % 3 == 0 && result[result.length - 1] == 0) {
    console.log(result)
} else {
    console.log(-1)
}
