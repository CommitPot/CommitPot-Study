let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

let arr = []

for(let i = 1; i <= Number(input[0]); i++) {
    arr.push(input[[i]])
}

let data = [...new Set(arr)]

data.sort((a,b) => {
    if(a.length == b.length) {
        if(a > b) {
            return 1
        } else {
            return -1
        }
    }
    return a.length - b.length
    
})
data.map((res) => {
    console.log(res)
})
