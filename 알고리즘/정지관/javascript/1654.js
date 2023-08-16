let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n')

let [k, n] = input[0].split(' ').map(Number)

input.shift()
input.pop()

let start = 0;
let end = input.reduce((a, b) => Math.max(a, b))

let result = 0;

while(start <= end) {
    let mid = parseInt((start + end)/2)
    let total = 0;
    for(let i = 0; i < k; i++) {
        total += parseInt(input[i] / mid)
    }
    if(total < n) {
        end = mid - 1;
    } else {
        result = mid;
        start = mid + 1;
    }
}

console.log(result)
