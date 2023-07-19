function solution(array) {
    var answer = [0 , 0];
    
    array.map((res, idx) => {
        if(res > answer[0]) {
            answer[0] = res;
            answer[1] = idx;
        }
    })
    
    return answer;
}
