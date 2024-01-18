import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    val M = nextInt()
    val N = nextInt()
    var result = 0
    var minimum = 0
    
    for (i in N downTo M) {
        if (isPrime(i)) {
            result += i
            minimum = i
        }
    }
    
    if (result == 0) {
        print(-1)
    } else {
        print("$result\n$minimum")
    }
}

fun isPrime(num: Int): Boolean {
    if (num == 1) return false
    
    for (j in 2..num - 1) {
        if (num % j == 0) return false
    }
    
    return true
}
