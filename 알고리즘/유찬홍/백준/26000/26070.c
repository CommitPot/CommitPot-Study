#include <stdio.h>

int main() {
    int a[6];
    long long r = 0;
    for (int i = 0; i < 6; i++) scanf("%d", &a[i]);
    for (int i = 0; i < 3; i++) {
        if (a[i] < a[i + 3]) r += a[i], a[i + 3] -= a[i], a[i] = 0;
        else r += a[i + 3], a[i] -= a[i + 3], a[i + 3] = 0;
    }
    for (int i = 0; i < 4; i++) {
        int j = (i + 4) % 3;
        a[j + 3] += a[i % 3 + 3] / 3;
        a[i % 3 + 3] /= 3;
        if (a[j] < a[j + 3]) r += a[j], a[j + 3] -= a[j], a[j] = 0;
        else r += a[j + 3], a[j] -= a[j + 3], a[j + 3] = 0;
    }
    printf("%lld", r);
}
