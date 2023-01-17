fun main(args: Array<String>) = with(System.`in`.bufferedReader()){
    val set = mutableSetOf<Int>()
    repeat(10){
        set.add(readLine().toInt() % 42)
    }
    println(set.size)
}
