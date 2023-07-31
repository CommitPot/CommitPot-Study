let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
let map1 = new Map();

let arr1 = input[1].split(' ').map(Number);
let arr2 = input[2].split(' ').map(Number);

arr1.map((res) => map1.set(res, true))
arr2.map((res => {
    map1.has(res) ? map1.delete(res) : map1.set(res, true)
}))
console.log(map1.size)
