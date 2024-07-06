#include <stdio.h>

int main() {
    int s, k, a[101];
    scanf("%d %d", &s, &k);
    for (int i = 0; i < k; i++) a[i] = s / k;
    for (int i = 0; i < s % k; i++) a[i]++;
    long long r = 1;
    for (int i = 0; i < k; i++) r *= a[i];
    printf("%lld", r);
}
