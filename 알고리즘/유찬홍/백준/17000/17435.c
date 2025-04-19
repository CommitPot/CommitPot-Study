#include <stdio.h>

int main() {
    int n, a, b, s[19][200001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[0][i + 1]);
    }
    for (int i = 1; i < 19; i++) {
        for (int j = 1; j <= n; j++) {
            s[i][j] = s[i - 1][s[i - 1][j]];
        }
    }
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &a, &b);
        for (int i = 0; i < 19; i++) {
            if (a & (1 << i)) b = s[i][b];
        }
        printf("%d\n", b);
    }
}
