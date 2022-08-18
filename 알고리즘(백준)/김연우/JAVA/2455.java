
import java.util.Scanner;

public class Main {

    static int count = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int boardingNum = 0;

        for (int i = 0; i < 4; i++) {


            int out = sc.nextInt();
            int in = sc.nextInt();

            if (out == 0) {
                boardingNum = in;
            }

            else {
                boardingNum = boardingNum - out + in;
            }

            count = Math.max(count, boardingNum);

        }

        System.out.println(count);

    }

}
