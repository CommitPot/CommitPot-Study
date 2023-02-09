
private val br = System.`in`.bufferedReader()

fun main() {
    val (n, k) = br.readLine().split(" ").map { it.toInt() }
    val coins = Array(n) { br.readLine().toInt() }
    var result = 0; var left = k

    for (index in n-1 downTo 0){
        result += left / coins[index]
        left %= coins[index]
    }
    print(result)
}
