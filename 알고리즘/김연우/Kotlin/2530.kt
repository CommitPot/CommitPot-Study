import java.util.*

fun main() = with(Scanner(System.`in`)){
    var h = nextInt()
    var m = nextInt()
    var s = nextInt()
    var cookingSec = nextInt()

    if (s + cookingSec > 59) {
        m += ((s + cookingSec) / 60)
        s = (s + cookingSec) % 60

        if (m > 59) {
            h += m / 60
            m %= 60

            if (h > 23) {
                h %= 24
            }
        }
    } else {
        s += cookingSec
    }

    println("$h $m $s")
}

