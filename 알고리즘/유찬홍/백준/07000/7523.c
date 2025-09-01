#include <stdio.h>

int main() {
    int t;
    long long r, n, m;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%lld %lld", &n, &m);
        if (n >= 0 && m >= 0) r = m * (m + 1) / 2 - n * (n + 1) / 2 + n;
        else if (n < 0 && m >= 0) r = m * (m + 1) / 2 + n * (-n + 1) / 2;
        else r = -(n * (n - 1) / 2 - m * (m - 1) / 2 - m);
        printf("Scenario #%d:\n%lld\n\n", i + 1, r);
    }
}
