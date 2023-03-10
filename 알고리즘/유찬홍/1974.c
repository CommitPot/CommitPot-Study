#include <stdio.h>

typedef struct element {
    int in, idx;
} element;


int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n, c = 0, dp[10001] = {0}, bs[10001] = {0};
        element arr[10001];
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[j].in);
        }
        dp[0] = arr[0].in;
        for (int j = 1; j < n; j++) {
            if (dp[c] < arr[j].in) dp[++c] = arr[j].in, arr[j].idx = c;
            else {
                int s = 0, e = c;
                while (s < e) {
                    int mid = (s + e) / 2;
                    if (dp[mid] < arr[j].in) s = mid + 1;
                    else e = mid;
                }
                dp[e] = arr[j].in;
                arr[j].idx = e;
            }
        }
        printf("%d\n", c + 1);
        int c1 = c;
        for (int j = n - 1; j >= 0; j--) {
            if (c == arr[j].idx) bs[c--] = j + 1;
        }
        for (int j = 0; j <= c1; j++) {
            printf("%d ", bs[j]);
        }
        printf("\n");
    }
    return 0;
}
