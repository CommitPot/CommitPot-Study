#include <stdio.h>

int main() {
    int n, a, d, r = 0;
    scanf("%d %d %d", &n, &a, &d);
    for (int i = 0, b, j; i < n; i++) {
        scanf("%d", &b);
        if (b == a) a += d, r++;
    }
    printf("%d", r);
}
