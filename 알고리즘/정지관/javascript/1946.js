let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
let num1 = Number(input[0])
let line = 1;
let arr1 = new Array(num1).fill(0).map(() => new Array(0));
let minVal = [];
let count = new Array(num1).fill(0).map(() => Number(new Array(0)));

for(let i = 0; i < num1; i++) {
    let n = Number(input[line])
    line += 1;
    for(let j = line; j < line + n; j++) {
        [x, y]= input[j].split(' ').map(Number)
        arr1[i].push({x, y});
    }
    
    arr1[i]?.sort((a, b) => a.x - b.x)
    minVal[i] = arr1[i][0].y
    for(let k = 1; k < n; k++) {
        if(arr1[i][k].y < minVal[i]) {
            count[i] += 1;
            minVal[i] = arr1[i][k].y
        }
    }
    count[i] += 1
    line += n;
}

console.log(count.join('\n'))
