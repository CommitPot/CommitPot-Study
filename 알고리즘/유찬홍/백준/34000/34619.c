#include <stdio.h>

int main() {
    int a, b, n, k, r = 0;
    scanf("%d %d %d %d", &a, &b, &n, &k);
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int l = 1; l <= n; l++) {
                if (++r == k) {
                    printf("%d %d", i, j);
                }
            }
        }
    }
}
