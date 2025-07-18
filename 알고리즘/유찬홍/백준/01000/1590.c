#include <stdio.h>

int main() {
    int n, m, a, b, c, r = 1e9;
    scanf("%d %d", &n, &m);
    while (n--) {
        scanf("%d %d %d", &a, &b, &c);
        while (a < m) a += b, c--;
        if (c < 1) continue;
        r = a - m > r ? r : a - m;
    }
    printf("%d", r == 1e9 ? -1 : r);
}
