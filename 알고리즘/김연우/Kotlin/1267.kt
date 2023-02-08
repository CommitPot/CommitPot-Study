import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    val calls = nextInt()
    var y = 0
    var m = 0
    repeat(calls) {
        val call = nextInt()
        y += 10 * (call / 30 + 1)
        m += 15 * (call / 60 + 1)
    }

    println(
        when {
            y == m -> "Y M $y"
            y < m -> "Y $y"
            else -> "M $m"
        }
    )
}
