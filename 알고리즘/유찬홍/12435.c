#include <stdio.h>

int main() {
    int t, n, m;
    scanf("%d", &t);
    int prime[1000001] = {}, cnt[1000001] = {};
    for (int i = 2; i <= 1000; i++) {
        for (int j = i * 2; j <= 1000000; j += i) {
            prime[j] = prime[j] ? prime[j] : i;
            cnt[j] += j / i > 1000 ? 2 : 1;
        }
    }
    for (int k = 1; k <= t; k++) {
        scanf("%d %d", &n, &m);
        int c = 0;
        for (int i = 2; i < n; i++) {
            if (cnt[i] == cnt[n] && prime[i] >= m) c++;
        }
        printf("Case #%d: %d\n", k, c);
    }
}
