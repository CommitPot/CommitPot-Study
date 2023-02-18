fun main(){
    var num:Int= readLine()!!.toInt()

    for(i in 1 .. num)
    {
        for(j in num-i+1 downTo 1)
        {
            print("*")

        }
        println()

    }

}
