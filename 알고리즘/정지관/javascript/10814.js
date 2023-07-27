let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

let arr = []

for(let i = 1; i <= Number(input[0]); i++) {
    [age, name] = input[i].split(' ')
    arr.push({age, name})
}
arr.sort((a, b) => 
    Number(a.age) - Number(b.age)
);

for(let a of arr) {
    console.log(a.age , a.name)
}
