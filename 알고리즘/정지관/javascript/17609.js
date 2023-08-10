let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

function rotate(n) {
    return n == n.split('').reverse().join('')
}

for(let i = 1; i <= Number(input[0]); i++) {
    if(rotate(input[i])) {
        console.log(0)
    } else {
        let l = input[i].length
        let found = false
        let temp = input[i]
        for(let j = 0; j < parseInt(l / 2); j++){
            if(input[i][j] != input[i][l - j - 1]) {
                if (rotate(temp.slice(0, j) + temp.slice(j + 1, l))) found = true;
                if (rotate(temp.slice(0, l - j - 1) + temp.slice(l - j, l))) found = true;
                break;
            }
        }
        if(found) console.log(1)
        else console.log(2)
    }
}
