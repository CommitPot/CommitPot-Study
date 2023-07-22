function solution(s) {
    var answer = s.split('').sort();
    let i =0;
    
    
    while(1) {
        if(answer[i] == answer[i+1]){
            answer = answer.filter((res) => res !== answer[i])
            i = 0;
        } else {
            i++;
        }
        
        if(answer[-1] == answer[i]) {
            break;
        }
        
    }


    return answer.sort().join('');
}
