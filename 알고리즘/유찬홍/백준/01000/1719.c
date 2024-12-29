#include <stdio.h>

int main() {
    int n, m, a, b, c, s[201][201], s1[201][201] = {0};
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            s[i][j] = 1e9;
        }
    }
    while (m--) {
        scanf("%d %d %d", &a, &b, &c);
        s[a][b] = s[b][a] = c;
        s1[b][a] = a;
        s1[a][b] = b;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (s[j][k] > s[j][i] + s[i][k]) {
                    s[j][k] = s[j][i] + s[i][k];
                    s1[j][k] = s1[j][i];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) printf("- ");
            else printf("%d ", s1[i][j]);
        }
        printf("\n");
    }
}
