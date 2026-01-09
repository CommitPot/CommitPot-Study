#include <stdio.h>

int main() {
    int n;
    long long r = 1;
    scanf("%d", &n);
    for (int i = 2; i <= n; i += 2) r = (i - 1) * r;
    printf("%lld", r);
}
