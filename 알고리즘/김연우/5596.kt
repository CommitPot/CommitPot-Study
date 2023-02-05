import java.util.*
import java.lang.String.format
fun main() {
    val s=Scanner(System.`in`)
    var sum=0
    var sum1=0
    for(i in 0 until 4) sum+=s.nextInt()
    for(i in 0 until 4) sum1+=s.nextInt()
    var max=Math.max(sum,sum1)
    print(max)
}
