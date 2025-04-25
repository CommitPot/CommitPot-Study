#include <stdio.h>
#define m 1000000007

int f(int x) {
    if (x < 1) return 1;
    long long r = f(x / 2);
    if (x & 1) return (int) (r * r % m * 2);
    return (int) (r * r % m);
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%d\n", f(n - 2) % m);
    }
}
