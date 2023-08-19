let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
let n = Number(input[0])
let stack = []
let result = []

for(let i = 1; i <= n; i++) {
    let line = input[i].split(' ')
    if(line[0] == 1) {
        stack.push(line[1])
    }
    else if(line[0] == 2) {
        if(stack.length === 0) {
          result.push(-1) 
        }  else {
            result.push(stack[stack.length -1])
            stack.pop()
        }
    }
    else if(line[0] == 3) {
        result.push(stack.length)
    }
    else if(line[0] == 4) {
        stack.length === 0 ? result.push(1) : result.push(0) 
    }
    else if(line[0] == 5) {
        stack.length === 0 ? result.push(-1) : result.push(stack[stack.length -1]) 
    }
}

console.log(result.join('\n'))
