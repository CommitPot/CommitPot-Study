import java.io.*;
import java.util.*;
import kotlin.collections.HashMap

fun main() {
    var br = BufferedReader(InputStreamReader(System.`in`));
    var sb = StringBuilder();

    var num = Integer.parseInt(br.readLine())
    var map : HashMap<Char, Int> = HashMap<Char, Int>();

    // 들어오는 이름의 첫 글자를 분리해서 집어넣어야함
    while(num-->0) {
        var name = br.readLine()[0]
        map.put(name, map.getOrDefault(name, 0) + 1);
    }


    for((key, value) in map) {
        if(value >= 5) {
            sb.append(key);
        }
    }

    if(sb.length == 0) {
        print("PREDAJA")
    }
    else {
        print(sb)
    }

}
