#include <stdio.h>

int main() {
    int t, n, p[1001] = {};
    p[0] = p[1] = 1;
    for (int i = 2; i < 32; i++) {
        if (!p[i]) {
            for (int j = i * 2; j < 1001; j += i) p[j] = 1;
        }
    }
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 2; i * i < n; i++) {
            for (int j = 2; j < n; j++) {
                if (!p[i] && !p[j] && !p[n - i - j]) {
                    printf("%d %d %d\n", i, j, n - i - j);
                    goto o;
                }
            }
        }
        printf("0\n");
        o:
    }
}
