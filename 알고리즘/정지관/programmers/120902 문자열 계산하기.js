function solution(my_string) {
    let a = my_string.split(' ')
    var answer = Number(a[0]);
    let arr = [];
    
    
    for(let i = 1; i < a.length + 1; i+= 2) {
        if(a[i] == '+'){
            answer += Number(a[i + 1])
        }
        if(a[i] == '-') {
            answer -= Number(a[i + 1])
        }
    }
    
    
    
    return answer;
}
