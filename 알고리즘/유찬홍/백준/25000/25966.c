#include <stdio.h>

int main() {
    int n, m, q, s[3001][3001], w[3001] = {};
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 0; i < n; i++) w[i] = i;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &s[i][j]);
        }
    }
    for (int i = 0, a, b, c; i < q; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (a & 1) {
            int k = w[b];
            w[b] = w[c];
            w[c] = k;
        }
        else {
            scanf("%d", &a);
            s[w[b]][c] = a;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (w[i] == j) {
                for (int k = 0; k < m; k++) {
                    printf("%d ", s[j][k]);
                }
                printf("\n");
            }
        }
    }
}
