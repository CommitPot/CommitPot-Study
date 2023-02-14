
import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val st = StringTokenizer(br.readLine(), " ")
    val n = st.nextToken().toInt()
    val m = st.nextToken().toInt()
    val queue = LinkedList<Int>()
    val list = mutableListOf<Int>()

    for (i in 1.. n) {
        queue.offerLast(i)
    }

    var count = 1

    while (queue.size > 0) {
        if (count % m == 0) {
            list.add(queue.pollFirst())
        }
        else {
            queue.offerLast(queue.pollFirst())
        }
        count += 1
    }

    print("<")
    for (i in list) {
        if (i == list.last()) {
            print("$i")
        }
        else {
            print("$i, ")
        }
    }
    print(">")
}
