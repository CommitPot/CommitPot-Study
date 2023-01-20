fun main(args: Array<String>) = with(System.`in`.bufferedReader()) {
    val S = readLine().toLong()

    var num = 1L
    var sum = 0L
    var result = 0L

    while (true) {
        sum += num
        result++

        if (sum > S) {
            result--
            break
        }
        num++
    }

    println(result)
}
