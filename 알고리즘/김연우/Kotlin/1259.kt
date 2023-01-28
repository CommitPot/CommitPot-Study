fun main() = with(System.`in`.bufferedReader()) {
    while (true) {
        val str = readLine()
        if (str == "0") break

        println(
            if (str == str.reversed()) "yes" else "no"
        )
    }
}
