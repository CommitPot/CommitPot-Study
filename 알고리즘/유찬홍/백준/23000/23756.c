#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0, j; i < n; i++) {
        scanf("%d", &j);
        int x = 360 - m + j, y = m + 360 - j;
        int z = abs(j - m) < x ? abs(j - m) : x;
        r += y < z ? y : z;
        m = j;
    }
    printf("%d", r);
}
