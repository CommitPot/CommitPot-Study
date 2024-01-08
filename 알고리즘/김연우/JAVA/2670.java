import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        double[] arr = new double[n+1];
        double[] dp = new double[n+1];
        double max = 0;
        for (int i = 1; i <= n; i ++){
            arr[i] = Double.parseDouble(br.readLine());
            dp[i] = Double.max(arr[i], dp[i-1] * arr[i]);
            max = Math.max(max, dp[i]);
        }
        System.out.println(String.format("%.3f", max));
    }

}
