fun main() {

    
    val list = mutableListOf<String>()


    for (i in 1..readln().toInt())
        list.add(readln())

    list.distinct()
        .sortedWith(
            compareBy<String> { it.length }
            .thenBy { it }
        )
        .forEach { println(it) }
}
