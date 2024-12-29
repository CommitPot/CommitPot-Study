#include <stdio.h>
#include <stdbool.h>

bool k(int v) {
    if (!v) return true;
    return (v % 10 == 5 || v % 10 == 8) && k(v / 10);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a[3], b[3][51], c[90001] = {}, r = 0;
        for (int i = 0; i < 3; i++) {
            scanf("%d", &a[i]);
            for (int j = 0; j < a[i]; j++) {
                scanf("%d", &b[i][j]);
            }
        }
        for (int i = 0; i < a[0]; i++) {
            for (int j = 0; j < a[1]; j++) {
                for (int k = 0; k < a[2]; k++) {
                    c[b[0][i] + b[1][j] + b[2][k]]++;
                }
            }
        }
        for (int i = 0; i < 90001; i++) {
            r += c[i] && k(i);
        }
        printf("%d\n", r);
    }
}
