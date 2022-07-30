# BigInteger

## 매우 큰 정수 표현

가끔 알고리즘 문제를 풀다 보면 기본적으로 정수를 표현하는 int 타입은 **–2,147,483,648 ~ 2,147,483,647**

범위의 정수만을 표현할 수 있다. 물론 이 보다 더 큰 값을 담을 수 있는 long 타입이 있지만, **-9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807**

사실 Long 타입은 억, 조 단위를 넘어선 경 단위이기 때문에 일반적인 상황에서는 이 정도 단위도 매우 크다.

하지만 상한,하한이 없는 거의 무한에 가까운 수를 표현해야 할 때도 있는데 이때는 BigInteger 클래스르 사용.

## 코드

```Kotlin
import java.math.BigInteger
import java.util.Scanner

fun main(args: Array<String>){
    val sc: Scanner = Scanner(System.`in`)
    var a = BigInteger(sc.next())
    var b = BigInteger(sc.next())

    println(a*b)

}
```

