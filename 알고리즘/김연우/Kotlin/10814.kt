mport java.util.*

fun main(args:Array<String>) = with(Scanner(System.`in`)){
    var n = nextInt()
    var list= arrayListOf<Pair<Int,String>>()

    for(i in 0 until n){
        list.add(Pair(nextInt(),nextLine()))
    }

    var sortList = list.sortedWith(compareBy({it.first}))

    for(i in 0 until n) {
        println("${sortList[i].first}${sortList[i].second}")
    }
}

