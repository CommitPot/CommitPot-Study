fun calculateChange(cents: Int) {
    val coinValues = arrayOf(25, 10, 5, 1)
    var remainingCents = cents

    val coins = coinValues.map { coinValue ->
        val count = remainingCents / coinValue
        remainingCents %= coinValue
        count
    }

    println(coins.joinToString(" "))
}

fun main() {
    val testCases = readLine()!!.toInt()

    repeat(testCases) {
        val cents = readLine()!!.toInt()
        calculateChange(cents)
    }
}
