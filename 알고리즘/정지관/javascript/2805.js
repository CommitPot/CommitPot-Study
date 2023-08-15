let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
let [n, m] = input[0].split(' ').map(Number)
let arr = input[1].split(' ').map(Number).sort((a, b) => b - a)

let start = 0
let end = arr.reduce((a, b) => Math.max(a, b));

let result = 0;

while(start <= end) {
    let total = 0;
    let mid = parseInt((start + end) / 2)
    for(let x of arr) {
        if(mid < x) total += x - mid 
    }
    if(total < m) {
        end = mid - 1;
    } else {
        result = mid;
        start = mid + 1;
    }
    
}


console.log(result)
