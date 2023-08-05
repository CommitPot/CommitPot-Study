let fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().split('\n');

let n = Number(input[0])
let arr = [];
let cnt = 1;

for(let i = 1; i <= n; i++) {
    [x, y] = input[i].split(' ').map(Number)
    arr.push({x, y})
}

arr.sort((a,b) => {
    if(a.y !== b.y){
        return a.y - b.y
    } else {
        return a.x - b.x
    }
})

let now = arr[0].y

for(let i = 1; i < n; i++) {
    if(arr[i].x >= now) {
        now = arr[i].y;
        cnt += 1;
    }
}
console.log(cnt)
