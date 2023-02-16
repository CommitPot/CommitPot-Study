import java.io.BufferedReader
import java.io.InputStreamReader

lateinit var stack: IntArray
var ptr = -1

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val testCase = br.readLine()!!.toInt()

    stack = IntArray(testCase)


    for (i in 0 until testCase) {
        when (val input = br.readLine()) {
            "top" -> println(top())
            "pop" -> println(pop())
            "empty" -> println(isEmpty())
            "size" -> println(size())
            else -> push(input.split(" ")[1].toInt())
        }
    }
}

fun pop(): Int {
    return if (ptr == -1) -1 else stack[ptr--]
}

fun push(n: Int) {
    stack[++ptr] = n
}

fun isEmpty(): Int {
    return if (ptr == -1) 1 else 0
}

fun size(): Int {
    return ptr + 1
}

fun top(): Int {
    return if (ptr == -1) -1 else stack[ptr]
}
