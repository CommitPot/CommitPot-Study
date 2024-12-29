#include <stdio.h>

int main() {
    int a, b, c, d = 0, e[3716] = {};
    scanf("%d %d %d", &a, &b, &c);
    for (int i = 0, j = 0; i < a; i++) {
        for (int k = 0; k < b; k++) e[j++] = 1;
        j += 5;
    }
    while (e[d]) d += c;
    printf("%d", d);
}
