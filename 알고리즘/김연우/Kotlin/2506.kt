fun main() {
    val n = readLine()!!.toInt()
    val results = readLine()!!.split(" ").map { it.toInt() }

    var totalScore = 0
    var currentScore = 0

    for (result in results) {
        if (result == 1) {
            currentScore++
            totalScore += currentScore
        } else {
            currentScore = 0
        }
    }

    println(totalScore)
}
