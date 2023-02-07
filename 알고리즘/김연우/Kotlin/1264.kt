import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    while (true) {
        val paragraph = readLine()
        if (paragraph[0] == '#') break

        println(
            paragraph.fold(0) { total, next ->
                total + disting(next)
            }
        )
    }
}

fun disting(char: Char): Int {
    return when (char) {
        'a', 'e', 'i', 'o', 'u' -> 1
        'A', 'E', 'I', 'O', 'U' -> 1
        else -> 0
    }
}
