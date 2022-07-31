import java.util.Scanner

fun main(args: Array<String>){
    val sc: Scanner = Scanner(System.`in`)

    while (true){

        var a = sc.nextInt()
        var b = sc.nextInt()

        if (a == 0 && b == 0){
            break
        }
        println(a+b)

    }
}
