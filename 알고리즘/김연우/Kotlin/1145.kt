
fun main(){

    val numList = readln().split("").map { it.toInt() }

    for (target in 1 until Int.MAX_VALUE){

        //나누어 떨어지는 횟수
        var dividedCnt = 0

        for (dividerIndex in 0 until numList.size) {
            // 입력받은 다섯 개의 자연수로 나누어 떨어질 때 마다 dividedCnt + 1
            if (target % numList[dividerIndex] == 0) dividedCnt++

        }
        // 입력받은 다섯 개의 자연수로 나누어진 횟수가 3이상이면 적어도 대부분의 배수
        if (dividedCnt >= 3){
            println(target)
            break
        }
    }
}
