import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val n = readLine().toInt()

    for(i in 0 until n) {
        val str = readLine()
        solve(str)
    }
}

fun solve(str: String){
    val stack = Stack<Char>()

    for(i in str){
        // 여는 괄호면 추가
        if(i == '('){
            stack.add(i)
        }
        // 닫는 괄호일 때
        else if(i == ')'){
            // 비어 있을 때
            if(stack.isEmpty()){
                println("NO")
                return
            }
            // 짝이 맞지 않을 때
            if(stack.pop() == ')'){
                println("NO")
                return
            }
        }
    }

    // 연산 종료 시 스택이 비어있어야 YES
    if(stack.isEmpty()){
        println("YES")
    }
    else{
        println("NO")
    }
}
