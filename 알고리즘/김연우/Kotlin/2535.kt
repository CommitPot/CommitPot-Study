import java.util.StringTokenizer
fun main() = with(System.`in`.bufferedReader()){
    
    val n = readln().toInt()
    
    val arr = Array(n) { intArrayOf(0, 0, 0) }
    repeat(n) {
        val st = StringTokenizer(readLine())
        arr[it][0] = st.nextToken().toInt()
        arr[it][1] = st.nextToken().toInt()
        arr[it][2] = st.nextToken().toInt()
    }

    // arr[] 배열의 세번째 국가를 기준으로 정렬
    arr.sortByDescending { it[2] }

    val countries = Array(n + 1) { 0 }
    var cnt = 0
    arr.forEach {
        if (cnt == 3) return
        if (countries[it[0]] < 2) {
            println("${it[0]} ${it[1]}")
            countries[it[0]]++
            cnt++
        }
    }
}
