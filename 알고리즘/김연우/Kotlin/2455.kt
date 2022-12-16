import java.io.BufferedReader
import java.io.InputStreamReader

fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))) {
    var max = 0
    var persons = 0

    repeat(4) {
        val (i, o) = readLine().split(" ").map { it.toInt() }
        persons += (o - i)
        if (max < persons) max = persons
    }

    println(max)
}
