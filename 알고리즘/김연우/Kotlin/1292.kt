import java.util.*

fun main() = with(Scanner(System.`in`)){
    val arr = arrayListOf<Int>()
    var sum = 0

    // 1부터 1000까지의 수열을 생성하여 리스트에 저장
    for(i in 1 .. 1000){
        for(j in 1 .. i){
            arr.add(i)
        }
    }

    // 구간의 시작과 끝 입력
    val a = nextInt()
    val b = nextInt()

    // 입력 받은 거 합 계산
    for(i in a-1 until b){
        sum += arr[i]
    }

    //출력
    println(sum)
}
