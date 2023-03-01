#include <stdio.h>

int main() {
    int t, n, m, k, arr[200002];
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d %d %d", &n, &m, &k);
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[j]);
        }
        if (n != m) {
            for (int j = 0; j < m; j++) {
                arr[n + j] = arr[j];
            }
            n += m - 1;
        }
        int sum = 0, s = 0, e = m - 1, count = 0;
        for (int j = 0; j < m; j++) {
            sum += arr[j];
        }
        while (e < n) {
            if (sum < k) count++;
            sum -= arr[s++];
            sum += arr[++e];
        }
        printf("%d\n", count);
    }
    return 0;
}