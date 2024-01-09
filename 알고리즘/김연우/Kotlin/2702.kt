fun main() {
    val t = readLine()!!.toInt()

    repeat(t) {
        val (a, b) = readLine()!!.split(" ").map { it.toInt() }
        val lcm = findLCM(a, b)
        val gcdValue = a.toBigInteger().gcd(b.toBigInteger()).toInt()
        println("$lcm $gcdValue")
    }
}

fun findLCM(a: Int, b: Int): Int {
    return (a * b) / a.toBigInteger().gcd(b.toBigInteger()).toInt()
}
