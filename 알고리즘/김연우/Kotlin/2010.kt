fun main() {
    var result = 0
    repeat(readln().toInt()) {
        result += readln().toInt() - 1
    }
    println(result + 1)
}
