fun main(){
    val num = readLine()!!.toInt()
    for(i in 0 until num){
        var arr1 = readLine()!!.split(" ").map{it.toInt()}
        sol(arr1)
    }
 
}
 
fun sol(arr: List<Int>){
    var a = 0
    var b = 0
    var count = 1
    loop@ for(i in 0 until arr[1]){
        for(k in 0 until arr[0]){
            if(count==arr[2]){
                a=k
                b=i
                break@loop
            }
            count++
        }
    }
    if(b<9){
        println("${a+1}0${b+1}")
    }
    else
        println("${a+1}${b+1}")
 
}
