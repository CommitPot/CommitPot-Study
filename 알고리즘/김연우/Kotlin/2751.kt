import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {

    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = System.out.bufferedWriter()
    val n = br.readLine().toInt()

    // 배열 초기화
    val list = BooleanArray(2000001)

    // 나타난 숫자 표시
    for (i in 0 until n) {
        list[br.readLine().toInt()+1000000] = true
    }

    val sb = StringBuilder()
    for (i in list.indices) {
        if (list[i]) {
            sb.append("${i-1000000}\n")
        }
    }
    
    bw.write(sb.toString())
    bw.close()
    br.close()
}
