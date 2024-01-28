fun josephusPermutation(n: Int, k: Int): List<Int> {
    val result = mutableListOf<Int>()
    val queue = (1..n).toMutableList()

    var index = 0
    while (queue.isNotEmpty()) {
        index = (index + k - 1) % queue.size
        result.add(queue.removeAt(index))
    }

    return result
}

fun main() {
    val (n, k) = readLine()!!.split(" ").map { it.toInt() }
    val josephusResult = josephusPermutation(n, k)

    println("<${josephusResult.joinToString(", ")}>")
}
