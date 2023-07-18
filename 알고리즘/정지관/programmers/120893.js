// 대문자인지 확인하는 함수
function isUpperCase(str) {
  return str === str.toUpperCase();
}

// 소문자인지 확인하는 함수
function isLowerCase(str) {
  return str === str.toLowerCase();
}

function solution(my_string) {
    var answer = '';
    
    my_string.split('').map((res) => { 
        if(isUpperCase(res)) {
            answer += res.toLowerCase();
        } else {
            answer += res.toUpperCase();
        }
    })
    
    return answer;
}
