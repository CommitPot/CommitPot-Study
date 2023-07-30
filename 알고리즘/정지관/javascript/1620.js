let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
let [N, M] = input[0].split(' ').map(Number);
let arr1 = []
let map1 = new Map()

for(let i = 1; i <= N; i++) {
    map1.set(input[i], i)
    map1.set(i.toString(), input[i])
}

for(let i = 1 + N; i < N + 1 + M; i++) {
    console.log(map1.get(input[i]))
}

