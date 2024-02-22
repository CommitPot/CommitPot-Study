fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    val testCase = br.readLine().toInt()

    val dp = IntArray(41)
    dp[1] = 1
    for(i in 2 .. 40) {
        dp[i] = dp[i - 1] + dp[i - 2]
    }

    repeat(testCase) {
        val num = br.readLine().toInt()

        if(num==0) {
            bw.append("1 0\n")
        } else {
            bw.append("${dp[num-1]} ${dp[num]}\n")
        }
    }

    bw.write("")
    bw.flush()
    bw.close()
    br.close()
}
