let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

let [start, end] = input[0].split(' ').map(res => Number(res));
let cnt = 1;
let now = end;

while(now >= 0 && start != now) {
    if(now == 0) {
        cnt = -1;
        break;
    } else if(now % 2 == 0) {
        now /= 2;
        cnt += 1
    } else if(now % 10 == 1) {
        now -= 1;
        now /= 10;
        cnt += 1
    }  else {
        cnt = -1;
        break;
    }
}

console.log(cnt)
