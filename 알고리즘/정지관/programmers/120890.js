function solution(array, n) {
    var answer = 100;
    var answer2;
    
    array.map((res) => {
        if(Math.abs(res - n) < answer) {
            answer = Math.abs(res - n);
            answer2 = res
        }
        else if(Math.abs(res - n) == answer) {
            if(res < answer2) {
                answer2 = res;
            }
        }
    })
    
    return answer2;
}
