#include <stdio.h>

int main() {
    long long n, m, a[50], s = 0;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    scanf("%lld", &m);
    for (int i = 0; i < n; i++) {
        s += a[i] / m * m;
        if (a[i] % m) s += m;
    }
    printf("%lld", s);
}
