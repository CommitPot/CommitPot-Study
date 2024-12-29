#include <stdio.h>

int main() {
    int n, k, a[2][10001] = {};
    long long r = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0, b; i < n * 2; i++) {
        scanf("%d", &b);
        a[i / n][b]++;
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            if (i == j) continue;
            r += (long long) a[0][i] * a[1][j];
        }
    }
    printf("%lld", r);
}
