let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

let mySet = new Set();

let answer = ''
let arr1 = input[1].split(' ').map((res) => mySet.add(res))
let arr2 = input[3].split(' ').map(res => {
    if(mySet.has(res)) {
        answer += '1\n'
    }else {
        answer += '0\n'
    }
})

console.log(answer)
