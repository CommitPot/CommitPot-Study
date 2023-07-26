let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
let arr = []

for(let i = 1; i <= Number(input[0]); i++) {
    [x, y] = input[i].split(' ').map((res) => Number(res))
    arr.push([x, y])
}
arr.sort((a,b) => {
    if(a[0] == b[0]) {
        return a[1] - b[1]
    }else{
        return a[0] - b[0];
    }
})
let answer = "";
arr.map((point) => {
    answer += point[0] + " " + point[1] + "\n";
})
console.log(answer);
