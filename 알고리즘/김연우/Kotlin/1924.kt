import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val st = StringTokenizer(br.readLine())

    val x = st.nextToken().toInt()
    val y = st.nextToken().toInt()

    val year = 2007 // 실제 입력값으로 대체해야 함
    val isLeapYear = isLeapYear(year)

    val daysInMonth = intArrayOf(0, 31, if (isLeapYear) 29 else 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31)

    val daysOfWeek = arrayOf("SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT")

    var totalDays = y
    for (month in 1 until x) {
        totalDays += daysInMonth[month]
    }

    val dayOfWeek = daysOfWeek[totalDays % 7]
    println(dayOfWeek)
}

fun isLeapYear(year: Int): Boolean {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)
}
