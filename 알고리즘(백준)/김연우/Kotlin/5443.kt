import java.util.Scanner

fun main(args: Array<String>){
    val sc: Scanner = Scanner(System.`in`)
    var min = 2000
    //for문의 조건애는 주로 연산자인 in을 사용한다.
    for (i in 0..2){
        val a = sc.nextInt()
        if (min > a){
            min = a
        }
    }

    var min2 = 2000
    for (i in 0..1){
        val b = sc.nextInt()
        if (min2 > b){
            min2 = b
        }
    }
    println(min + min2 - 50)
}
