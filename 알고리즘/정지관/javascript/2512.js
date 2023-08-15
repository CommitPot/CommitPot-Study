let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
let n = Number(input[0])
let arr = input[1].split(' ').map(Number).sort((a, b) => b - a)
let m = Number(input[2])

let start = 1; // 이진 탐색을 위한 시작점(start)과 끝점(end) 설정
let end = arr.reduce((a, b) => Math.max(a, b));

let result = 0;

while(start <= end) {
    let mid = parseInt((start + end) / 2)
    let total = 0;
    for(let x of arr) {
        total += Math.min(mid, x)
    }
    if(total <= m) {
        result = mid;
        start = mid + 1;
    } else {
        end = mid - 1;
    }
}


console.log(result)
