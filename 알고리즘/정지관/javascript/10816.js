let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
let n =  Number(input[0])
let arr1 = input[1].split(' ').map(Number).sort((a,b) => a - b)
let m = Number(input[2])
let arr2 = input[3].split(' ').map(Number)

function lowerBound(arr, target, start, end) {
    while(start < end) {
        let mid = parseInt((start + end) /2)
        if(arr[mid] >= target) end = mid;
        else start = mid + 1;
    }
    return end;
}

function upperBound(arr, target, start, end) {
     while(start < end) {
        let mid = parseInt((start + end) /2)
        if(arr[mid] > target) end = mid;
        else start = mid + 1;
    }
    return end;
}

function countByRange(arr, leftValue, rightValue) {
    let rightIndex = upperBound(arr, rightValue, 0, arr.length);
    let leftIndex = lowerBound(arr, leftValue, 0, arr.length);
    return rightIndex - leftIndex;
}

console.log(arr2.map(res => countByRange(arr1, res, res)).join(' '))
