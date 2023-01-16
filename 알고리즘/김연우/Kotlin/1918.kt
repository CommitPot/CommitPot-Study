import java.util.*

val br = System.`in`.bufferedReader()
fun main() = with(System.out.bufferedWriter()) {
    //input
    val stk = Stack<Char>()
    var answer = StringBuilder()
    br.readLine().forEach { ch ->
        if (ch.isLetter()) {
            answer.append(ch)
        } else if (ch == '(') {
            stk.push(ch)
        }
        //괄호 내부의 연산을 모두 pop
        else if (ch == ')') {
            while (stk.isNotEmpty() && stk.peek() != '(') {
                answer.append(stk.pop())
            }
            if (stk.isNotEmpty() && stk.peek() == '(') {
                stk.pop()
            }
        }
        //연산자가 들어오는 경우
        else {
            //ch보다 우선순위가 같거나 높은 경우 다 pop
            if (ch == '-' || ch == '+') {
                while (stk.isNotEmpty() && stk.peek() != '(') {
                    answer.append(stk.pop())
                }
            } else {
                while (stk.isNotEmpty() && stk.peek() != '(' && stk.peek() != '-' && stk.peek() != '+') {
                    answer.append(stk.pop())
                }
            }
            stk.push(ch)
        }
    }
    while (stk.isNotEmpty()) {
        answer.append(stk.pop())
    }
    //solve
    write("$answer")
    //output
    close()
}
