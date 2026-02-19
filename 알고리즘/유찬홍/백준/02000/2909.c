#include <stdio.h>

int main() {
    int c, k, v = 1;
    scanf("%d %d", &c, &k);
    if (k) {
        while (k--) v *= 10;
        printf("%d", c % v < v / 2 ? c - c % v : c + (v - c % v));
    } else printf("%d", c);
}
