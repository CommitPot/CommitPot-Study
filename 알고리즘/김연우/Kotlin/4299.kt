import java.util.*
import java.lang.String.format
fun main(args: Array<String>) {
    val s=Scanner(System.`in`)
    var a=s.nextInt()
    var b=s.nextInt()
    if((a+b)%2==1||a<b) print(-1)
    else{
        var n=(a+b)/2
        var m=a-n
        print(format("%d %d",n,m))
    }
}
