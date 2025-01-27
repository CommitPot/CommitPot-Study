#include <stdio.h>

int main() {
    int a, b, r = 0;
    scanf("%d %d", &a, &b);
    if (~a & 1) a++, r++;
    if (b & 1) b--, r++;
    printf("%d", (b - a + 1) / 2 + r);
}
