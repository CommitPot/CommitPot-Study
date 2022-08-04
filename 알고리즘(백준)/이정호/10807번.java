import java.util.Scanner;

public class Main {
<<<<<<< Updated upstream

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int[] arr = new int[N];
        int cnt = 0;

        for (int i = 0; i < N; i++) {
            arr[i] = sc.nextInt();
        }
        int v = sc.nextInt();

        for (int i = 0; i <= arr.length; i++) {
            if (arr[i] == v) {
                cnt++;
            }
        }
        System.out.println(cnt);
    }
}
=======
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] array = new int[N];
        int cnt = 0;

        for(int i = 0; i < N; i++) {
            array[i] = sc.nextInt();
        }

        int v= sc.nextInt();

        for(int i = 0; i < array.length; i++) {
            if (v == array[i]){
                cnt++;
            }
        }

        System.out.println(cnt);


    }
}
>>>>>>> Stashed changes
