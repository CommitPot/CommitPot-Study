#include <stdio.h>

int main() {
    int n, m, r;
    scanf("%d %d", &n, &m);
    r = m;
    if (n > 4) r = r < m - 500 ? r : m - 500;
    if (n > 9) r = r < m - m / 10 ? r : m - m / 10;
    if (n > 14) r = r < m - 2000 ? r : m - 2000;
    if (n > 19) r = r < m - m / 4 ? r : m - m / 4;
    printf("%d", r < 0 ? 0 : r);
}
