#include <stdio.h>

int main() {
    int a[23] = {1, 2}, t, x;
    for (int i = 2; i < 21; i++) a[i] = a[i - 1] + a[i - 2];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &x);
        int r = 0;
        for (int i = 20; i > 0; i--) {
            if (x >= a[i]) x -= a[i], r += a[i - 1];
        }
        printf("%d\n", r);
    }
}
