import java.util.Scanner

fun main(args: Array<String>) {
    val sc: Scanner = Scanner(System.`in`)
    var a = sc.nextInt()


    if(a >= 90 && a <= 100){
        println('A');
    }
    if(a >= 80 && a <= 89){
        println('B');
    }
    if(a >= 70 && a <= 79){
        println('C');
    }
    if(a >= 60 && a <= 69){
        println('D');
    }
    if(a >= 0 && a <= 59){
        println('F');
    }

}
