let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
let a = input[0].split(' ')

console.log(a.sort((a, b) => a - b).join(' '))
