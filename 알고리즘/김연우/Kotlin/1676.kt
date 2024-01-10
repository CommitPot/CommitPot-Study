import kotlin.math.min

fun main() {
    val n = readLine()!!.toInt()

    // 2와 5의 개수를 구하고 둘 중 작은 값을 선택
    val result = min(countFactors(n, 2), countFactors(n, 5))

    println(result.toString())
}

// 숫자 n!에서 factor의 개수를 세는 함수
fun countFactors(n: Int, factor: Int): Int {
    var count = 0
    var num = n

    while (num / factor > 0) {
        count += num / factor
        num /= factor
    }

    return count
}
