#include <stdio.h>

int main() {
    int n, a[5] = {};
    scanf("%d", &n);
    for (int i = 0, j; i < n; i++) scanf("%d", &j), a[j]++;
    a[4] += a[2] / 2;
    a[2] %= 2;
    if (a[2] && a[1]) {
        for (int i = 0; i < 2 && a[1]; i++) a[1]--;
        a[4]++, a[2]--;
    }
    for (int i = a[3]; i > 0; i--) {
        if (a[1]) a[1]--;
        a[3]--;
        a[4]++;
    }
    a[4] += a[1] / 4;
    a[1] %= 4;
    printf("%d", a[4] + !!a[3] + !!a[2] + !!a[1]);
}
