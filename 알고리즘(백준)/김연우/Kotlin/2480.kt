import java.util.Scanner

fun main(args: Array<String>) {
    val sc: Scanner = Scanner(System.`in`)
    var a = sc.nextInt()
    var b = sc.nextInt()
    var c = sc.nextInt()

    if (a == b && a == c) {
        println(10000 + a * 1000);
    } else if (a == b || a == c) {
        println(1000 + a * 100);
    } else if (b == c) {
        println(1000 + b * 100);
    } else {
      println((Math.max(a, Math.max(b, c)) * 100));
    }

}
