import java.util.Scanner;
public class HelloJava {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] arr = { in.nextInt(), in.nextInt(), in.nextInt(),
                in.nextInt(), in.nextInt(), in.nextInt(),
                in.nextInt(), in.nextInt(), in.nextInt() };
        

        int count = 0;
        int max = 0;
        int index = 0;

        for(int value : arr) {
            count++;

            if(value > max) {
                max = value;
                index = count;
            }
        }
        System.out.print(max + "\n" + index);

    }
}
