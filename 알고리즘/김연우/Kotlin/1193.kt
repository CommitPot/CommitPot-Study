import java.util.*

fun main() = with(Scanner(System.`in`)){
    val x = nextInt()
    var sum = 1 // 분자 분모 합
    var tmp = 0 // 같은 분자분모 합 레벨에서 가장 뒤의 순서

    // 분자 분모 합 구하기
    while(tmp < x){
        tmp += sum
        sum++
    }

    // 합이 짝수
    if(sum%2 == 0){
        val molecule = (tmp - x + 1)
        val denominator = sum - molecule
        println("$molecule/$denominator")
    }

    // 합이 홀수
    else{
        val denominator = (tmp - x + 1)
        val molecule = sum - denominator
        println("$molecule/$denominator")
    }
}
