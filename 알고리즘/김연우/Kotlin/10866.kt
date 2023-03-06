import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val num = br.readLine().toInt()
    val queue = LinkedList<Int>()

    for(i in 0 until num) {
        val st = StringTokenizer(br.readLine(), " ")
        val n = st.nextToken()

        when(n) {
            "push_front" -> {
                val m = st.nextToken().toInt()
                queue.offerFirst(m)
            }
            "push_back" -> {
                val m = st.nextToken().toInt()
                queue.offerLast(m)
            }
            "pop_front" -> if (queue.size < 1) println(-1) else println(queue.pollFirst())
            "pop_back" -> if (queue.size < 1) println(-1) else println(queue.pollLast())
            "size" -> println(queue.size)
            "empty" -> if (queue.size == 0) println(1) else println(0)
            "front" -> if(queue.size != 0) println(queue.first) else println(-1)
            "back" -> if(queue.size != 0) println(queue.last) else println(-1)
        }
    }
}
