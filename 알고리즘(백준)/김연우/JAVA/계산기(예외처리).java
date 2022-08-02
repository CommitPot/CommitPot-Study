import java.util.Scanner;
public class HelloJava {
    public static void main(String[] args){
        int a = 0;
        int b = 0;
        String sign;
        Scanner sc = new Scanner(System.in);

        System.out.println("첫번쨰 값 : ");
        a = sc.nextInt();

        System.out.println("두번째 값 : ");
        b = sc.nextInt();

        System.out.println("부호(+, -, *, /) : ");
        sign = sc.next();

        if(sign.equals("+")) {
            System.out.println(a+"+"+b+"="+(a+b));
        }
        else if(sign.equals("-")) {
            System.out.println(a+"-"+b+"="+(a-b));
        }
        else if(sign.equals("*")) {
            System.out.println(a+"*"+b+"="+(a*b));
        }
        else if(sign.equals("/")) {
            try{
                System.out.println(a+"/"+b+"="+(a/b));
            }
            catch (ArithmeticException e){
                System.out.println("오류");
            }
        }
        else {
            System.out.println("알수없는 연산자입니다 ... ");
        }

    }

}
