import java.io.*
import java.util.*
private lateinit var st : StringTokenizer
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    st = StringTokenizer(br.readLine())
    
    val num1 = st.nextToken().toInt()
    if(num1 == 1) find_ascending()
    else if(num1 == 8) find_descending()
    else print("mixed")
}

fun find_ascending() {
    for(i in 2..8) if(st.nextToken().toInt() != i) { print("mixed"); return }
    print("ascending")
} 

fun find_descending () {
    for(i in 7 downTo 1) if(st.nextToken().toInt() != i) { print("mixed"); return }
    print("descending")
}
