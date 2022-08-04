import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a, b;
        a = sc.nextLong();
        b = sc.nextLong();
        long c = (a + b) * (a - b);
        System.out.println(c);

    }
}

