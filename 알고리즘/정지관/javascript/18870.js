let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
let input2 = input[1].split(' ').map((res) => Number(res))

const set = new Set(input2);
const uniqueArr = [...set];

let number = new Map();


let input3 = uniqueArr.sort((a, b) => a - b)
for(let i = 0; i < uniqueArr.length; i++) {
    number.set(input3[i], i)
}

let arr = []
input2.map((res) => arr.push(number.get(res)))
console.log(arr.join(' '))
