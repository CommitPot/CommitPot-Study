import java.util.*
fun main(args: Array<String>) {
    val s=Scanner(System.`in`)
    var a=s.nextInt();
    var b=s.nextInt();
    var c=s.nextInt();
    var n=c-b
    
    if(n<=0) print(-1)
    else print(a/n+1)
}
