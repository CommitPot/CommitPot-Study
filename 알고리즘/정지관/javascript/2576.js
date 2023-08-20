let fs = require('fs')
let input = fs.readFileSync('/dev/stdin').toString().split('\n').map(Number);
let total = 0;
let last = 100;

input.map((res) => {
    if(res%2 == 1) {
        total += res;
        last = Math.min(res, last);
    }
})

if(total == 0) {
    console.log(-1)
} else {
    console.log(total)  
    console.log(last)
}
