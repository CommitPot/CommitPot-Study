import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    var TC = readLine().toInt()
    var N = 0

    var ans = MutableList(11,{i->i})

    ans[1] = 1
    ans[2] = 2
    ans[3] = 4

    for (i in 1..TC) {
        N = readLine().toInt()

        for (i in 4..N) {
            ans[i] = ans[i - 3] + ans[i - 2] + ans[i - 1]
        }
        println(ans[N])
    }
}
