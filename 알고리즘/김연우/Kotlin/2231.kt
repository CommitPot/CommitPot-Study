fun main(){
    val n = readLine()!!.toInt()
    val length = n.toString().length
    for(i in n-9*length..n){
        if (sums(i) + i ==n) {
            print(i);return
        }
    }
    print(0)
}

fun sums(number: Int): Int{
    var sum = 0
    for (c in number.toString()) sum += c - '0'
    return sum
}
