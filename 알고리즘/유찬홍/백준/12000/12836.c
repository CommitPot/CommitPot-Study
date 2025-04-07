#include <stdio.h>

int main() {
    int n, m;
    long long int s[10001] = {};
    scanf("%d %d", &n, &m);
    for (int i = 0, a, b, c; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (a & 1) for (int j = b; j <= n; j++) s[j] += c;
        else printf("%lld\n", s[c] - s[b - 1]);
    }
}
