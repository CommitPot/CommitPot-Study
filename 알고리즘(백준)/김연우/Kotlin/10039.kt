import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    var arr = Array(5) { nextInt()}// 5개의 숫자를 입력받음
    
    for(i in 0..4){
      if(arr[i]<40){
        arr[i]=40 // 40 미만인 수를 40으로 바꿈
      }
    }
    
    println(arr.sum()/5)
}
