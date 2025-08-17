#include <stdio.h>

int main() {
    int n;
    long long a, r = 0;
    scanf("%d %lld", &n, &a);
    for (int i = 1, b; i < n; i++) {
        scanf("%d", &b);
        r = (r + a * b) % 1000000007;
        a += b;
    }
    printf("%lld", r);
}
