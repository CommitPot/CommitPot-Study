#include <stdio.h>

int main() {
    int n, a[32] = {}, d, r = 1;
    scanf("%d", &n);
    for (int i = 0, b, c; i < n; i++) {
        scanf("%d %d", &b, &c);
        while (b < c) a[b++]++;
    }
    scanf("%d", &d);
    for (int i = 1; i < 32; i++) {
        if (d < a[i]) r = 0;
    }
    printf("%d", r);
}
