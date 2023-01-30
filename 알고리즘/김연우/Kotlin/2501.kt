import java.util.*

fun main() = with(Scanner(System.`in`)){

    var n = nextInt()
    var k = nextInt()
    var count = 0

    for(i in 1 .. n){
        if(n%i == 0){
            count++
            if(count == k){
                println(i)
            }
        }
    }

    if(count<k) println(0)
}
