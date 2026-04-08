#include <stdio.h>

int main() {
    int n, a[300001];
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), r += a[i];
    for (int i = 0; i < n; i++) if (a[i] < -r) r += -r - a[i];
    printf("%lld", r);
}
