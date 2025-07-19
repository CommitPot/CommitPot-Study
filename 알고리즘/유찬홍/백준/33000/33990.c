#include <stdio.h>

int main() {
    int n, r = 601;
    scanf("%d", &n);
    for (int i = 0, a, b, c; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        int d = a + b + c;
        if (d < r && d >= 512) r = d;
    }
    printf("%d", r == 601 ? -1 : r);
}
