let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
 
let zero = input[0].split('1').filter(res => res !== '')
let one = input[0].split('0').filter(res => res !== '')

if(zero.length > one.length) {
    console.log(one.length)
} else {
    console.log(zero.length)
}
