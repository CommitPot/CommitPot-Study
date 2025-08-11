#include <stdio.h>

int main() {
    int n, x, s, c, p, r = 0;
    scanf("%d %d %d", &n, &x, &s);
    while (n--) {
        scanf("%d %d", &c, &p);
        if (c <= x && p > s) r = 1;
    }
    printf("%s", r ? "YES" : "NO");
}
