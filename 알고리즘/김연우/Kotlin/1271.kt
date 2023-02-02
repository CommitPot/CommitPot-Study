import java.io.*
import java.math.BigInteger
import java.util.*

fun main() {

    val br = BufferedReader(InputStreamReader(System.`in`))

    val input = br.readLine()
    val st = StringTokenizer(input, " ")
    var all = BigInteger(st.nextToken()) //가진 돈
    var count = BigInteger(st.nextToken()) //생명체의 수

    //각 생명체에게 주는 돈
    println(all/count)
    //나머지
    println(all%count)
}
