import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Integer> a = new ArrayList<>();
        int result = 0;
        //5회 입력
        for (int i = 0; i < 5; i++) {
            a.add(scanner.nextInt());
        }
        //합
        for (Integer x : a) {
            result += x;
        }
        //출력
        System.out.println(result);
    }
}
