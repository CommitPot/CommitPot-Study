
import java.util.*
import java.io.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))

    val st = StringTokenizer(br.readLine())
    val N = st.nextToken().toLong()
    val M = st.nextToken().toLong()

    val gcd = GCD(N, M)
    val lcm = LCM(N, M, gcd)
    println(gcd)
    println(lcm)
} // End of main

private fun GCD(a: Long, b: Long): Long {
    if (a % b == 0L) return b
    return GCD(b, a % b)
} // End of GCD

private fun LCM(N: Long, M: Long, gcd: Long): Long {
    return (N * M) / gcd
} //
