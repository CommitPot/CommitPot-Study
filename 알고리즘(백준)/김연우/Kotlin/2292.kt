import java.util.*

fun main(args: Array<String>){
    val sc = Scanner(System.`in`)

    var N = sc.nextInt()
    var count = 1 // 겹 수(최소 루트)
    var  range = 2 // 범위(최솟값 기준)

    if (N == 1){
        print(1)
    }

    else{
        while (range <= N){ // 범위가 N보다 커지기 직전까지 반복
            range = range + (6 * count) // 다음 범위의 최솟값으로 초기화
            count++ // count 1 증가
        }
        print(count)
    }


}
