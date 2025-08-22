#include <stdio.h>

int main() {
    int n, a, r = 0, w = 0;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &a);
        if (w >= a) r = -1e9;
        int x = a - w - 1;
        r += x / 2 + x % 2 + 1;
        w = a + 1;
    }
    printf("%d\n", r < 0 ? -1 : r);
}
