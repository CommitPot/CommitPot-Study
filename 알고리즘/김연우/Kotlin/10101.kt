import java.util.*
fun main() = with(Scanner(System.`in`)){
    var a = nextInt()
    var b = nextInt()
    var c = nextInt()


    if (a+ b + c == 180){
        if (a == b  && b == c) println("Equilateral")
        else if (a == b || b == c || c == a) println("Isosceles")
        else println("Scalene")
    }
    else println("Error")

}
