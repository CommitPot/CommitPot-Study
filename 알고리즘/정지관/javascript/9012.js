let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
let n = Number(input[0])

for(let i = 1; i <= n; i++) {
    let arr = []
    let current = input[i];
    for(let j = 0; j < current.length; j++) {
        if(current[j] == '(') {
            arr.push('(')
        } else {
            if(arr.length >= 1) {
                arr.pop()
            } else {
                arr.push('')
                break ;
            }
        }
    }
    if(arr.length == 0) console.log('YES')
    else console.log('NO')
}
