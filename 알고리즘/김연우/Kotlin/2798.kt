import java.util.*
import kotlin.collections.ArrayList

fun main() = with(Scanner(System.`in`)){
    var n = 0
    var m = 0
    var sum = 0
    var max = 0

    n = nextInt()
    m = nextInt()

    val arr : ArrayList<Int> = arrayListOf()

    for(i in 0 until n){
        arr.add(nextInt())
    }

    for (one in 0 until n){
        for(two in one+1 until n){
            for(three in two+1 until n){
                sum = arr[one] + arr[two] + arr[three]
                if (sum > max && sum <= m) max=sum
            }
        }
    }

    println(max)

}
