import java.util.*
fun main() = with(Scanner(System.`in`)){
    val a = nextInt()
    val b = nextInt()
    val v = nextInt()

    print(if((v-a)%(a-b) == 0) (v-a)/(a-b) +1 else (v-a)/(a-b) +2)
}
