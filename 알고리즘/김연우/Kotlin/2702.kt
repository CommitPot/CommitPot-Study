fun main() {
    val t = readLine()!!.toInt()

    repeat(t) {
        val (a, b) = readLine()!!.split(" ").map { it.toInt() }
        val lcm = findLCM(a, b)
        val gcdValue = gcd(a, b)
        println("$lcm $gcdValue")
    }
}

fun gcd(a: Int, b: Int): Int {
    return if (b == 0) a else gcd(b, a % b)
}

fun findLCM(a: Int, b: Int): Int {
    return (a / gcd(a, b)) * b
}
