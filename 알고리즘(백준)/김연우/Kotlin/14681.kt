import java.util.Scanner

fun main(args: Array<String>) {
    val sc: Scanner = Scanner(System.`in`)
    var a = sc.nextInt()
    var b = sc.nextInt()
    if(a> 0){
        if(b > 0){
          println(1);
        }
        else {
           println(4);
        }
    }
    else {
        if(b > 0){
           println(2);

        }
        else {
            println(3);

        }
    }
}
