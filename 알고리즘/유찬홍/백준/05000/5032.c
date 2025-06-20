#include <stdio.h>

int main() {
    int e, f, c, r = 0;
    scanf("%d %d %d", &e, &f, &c);
    e += f;
    while (e >= c) {
        r++;
        e -= c - 1;
    }
    printf("%d", r);
}
