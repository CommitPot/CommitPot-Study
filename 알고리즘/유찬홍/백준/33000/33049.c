#include <stdio.h>

int main() {
    int a, b, c, d = 0, e = 0;
    scanf("%d %d %d", &a, &b, &c);
    if (a % 3) {
        d = a / 3 + 1;
        c -= 3 - a % 3;
    } else d = a / 3;
    if (b % 4) {
        e = b / 4 + 1;
        c -= 4 - b % 4;
    } else e = b / 4;
    int f = c;
    while (c > 0 && c % 4) c -= 3;
    if (c % 4 || c < 0) printf("-1");
    else printf("%d %d", d + (f - c) / 3, e + c / 4);
}
