function solution(numbers) {
    var arr = numbers.sort((i, j) => j - i)
    var answer;
    if(arr[0] * arr[1] > arr[numbers.length - 1] * arr[numbers.length - 2]) {
        answer = arr[0] * arr[1]
    }
    else {
        answer = arr[numbers.length - 1] * arr[numbers.length - 2]
    }
    
    return answer;
}
