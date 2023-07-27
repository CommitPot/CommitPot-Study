let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

let lst = input[0].split('-');
let arr = []

lst.map((res) => {
    if(res.includes('+')) {
        arr.push(res.split('+').map((res) => Number(res)).reduce((arr, res) => arr += res ))
    }else {
        arr.push(Number(res));
    }
})

let total = arr[0];

for(let i = 1; i < arr.length; i++) {
    total -= arr[i]
}
console.log(total)
