import java.io.BufferedReader
import java.io.InputStreamReader

fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))) {
    val (a, b) = readLine().split(" ").map {
        it.toLong()
    }
    println((a + b) * (Math.abs(b - a) + 1) / 2)
}
