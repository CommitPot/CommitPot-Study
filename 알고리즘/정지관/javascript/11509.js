let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().split('\n');

let n = input[0]
let cnt = 0;
let input2 = input[1].split(' ').map(Number)
let arrow = new Array(1000001).fill(0);

for(let x of input2) {
    if(arrow[x] > 0) {
        arrow[x] -= 1;
        arrow[x - 1] += 1;
    } else {
        arrow[x - 1] += 1;
        cnt += 1;
    }
}

console.log(cnt)
