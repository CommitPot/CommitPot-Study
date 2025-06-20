#include <stdio.h>

int main() {
    int n, m;
    while (scanf("%d", &n), n) {
        scanf("%d", &m);
        int p = n - m;
        if (p >= m) {
            if (m & 1) printf("%d %d %d\n", m + 1, p, p + 1);
            else printf("%d %d %d\n", m - 1, p + 1, p + 2);
        } else {
            if (m & 1) printf("%d %d %d\n", p, p + 1, m + 1);
            else printf("%d %d %d\n", p + 1, p + 2, m - 1);
        }
    }
}