#include <stdio.h>

int main() {
    int n;
    long long r;
    scanf("%d", &n);
    r = (long long) (n + 1) * n / 2;
    for (int i = 0, a; i < n; i++) scanf("%d", &a), r -= a;
    printf("%lld", -r + n);
}
