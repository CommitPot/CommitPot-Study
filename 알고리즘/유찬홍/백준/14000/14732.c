#include <stdio.h>

int main() {
    int n, a, b, c, d, e[501][501] = {}, r = 0;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        for (int i = a; i < c; i++) {
            for (int j = b; j < d; j++) {
                e[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < 501; i++) {
        for (int j = 0; j < 501; j++) {
            r += e[i][j];
        }
    }
    printf("%d", r);
}
