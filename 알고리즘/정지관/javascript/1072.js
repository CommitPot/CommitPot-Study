let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

let [x, y] = input[0].split(' ').map(Number)
let start = 0;
let end = 1000000000;
let result = 0;
let C = Math.floor(y* 100/x)


if(x === y || C + 1 == 100) console.log(-1)
else {
    while(start <= end) {
        let mid = parseInt((start+end)/2)
        let new_num = Math.floor((y+mid)* 100 / (x+mid))
        if(C !== new_num) {
            result = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    console.log(result)
}
