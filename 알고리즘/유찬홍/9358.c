#include <stdio.h>

int main() {
    int t, n;
    long long r[101];
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        scanf("%d", &n);
        for (int j = 0; j < n; j++) scanf("%lld", &r[j]);
        int j = 0, k = n - 1;
        while (k > 1) {
            while (j <= k) {
                r[j++] += r[k--];
            }
            j = 0, k++;
        }
        printf("Case #%d: %s\n", i, r[0] > r[1] ? "Alice" : "Bob");
    }
}
