import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    
    var n = readLine().toInt()
    
    var q:Queue<Int> = LinkedList<Int>()
    
    while(n-->0){
        
        var ip=readLine().split(' ')
        
        when(ip[0]){
            "push"->q.add(ip[1].toInt())
            "pop"-> println(if(q.isEmpty()) -1 else q.poll())
            "empty"->println(if(q.isEmpty()) 1 else 0)
            "front"->println(if(q.isEmpty()) -1 else q.peek())
            "back"->println(if(q.isEmpty()) -1 else q.last())
            
            else->println(q.size)
        }
    }
}
