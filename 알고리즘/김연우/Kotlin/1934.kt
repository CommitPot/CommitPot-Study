fun main(args: Array<String>) = with(System.`in`.bufferedReader()) {
    repeat(readLine().toInt()) {
        val (p, q) = readLine().split(" ").map { it.toInt() }
        println(p * q / gcd(p, q))
    }
}

fun gcd(p: Int, q: Int): Int {
    if (q == 0) return p
    return gcd(q, p % q)
}
