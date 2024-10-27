#include <stdio.h>

int main() {
    long long n, a[80001], r = 0, t = 1;
    scanf("%lld %lld", &n, &a[1]);
    for (int i = 1, j; i < n; i++) {
        scanf("%d", &j);
        while (t && a[t] <= j) t--;
        a[++t] = j, r += t - 1;
    }
    printf("%lld", r);
}
