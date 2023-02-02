import kotlin.math.min

fun main(args: Array<String>) {
    var min = Int.MAX_VALUE

    repeat(readln().toInt()) {
        val (a, b) = readln().split(" ").map { it.toInt() }

        if (a <= b) {
            min = min(a, b)
        }
    }

    if (min == Int.MAX_VALUE) {
        print(-1)
    } else print(min)
}
