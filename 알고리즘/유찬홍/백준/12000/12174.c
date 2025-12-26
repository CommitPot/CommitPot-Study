#include <stdio.h>

int main() {
    int n, t;
    char b[8001];
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        scanf("%d %s", &n, b);
        char r[1001];
        for (int j = 0, k = 0, l = 128; j < n * 8; j++, l /= 2) {
            if (b[j] == 'I') k += l;
            if (j % 8 == 7) {
                r[j / 8] = k;
                k = 0;
                l = 256;
            }
        }
        r[n] = 0;
        printf("Case #%d: %s\n", i, r);
    }
}
