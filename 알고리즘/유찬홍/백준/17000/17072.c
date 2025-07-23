#include <stdio.h>

int main() {
    int n, m;
    char r[400][401];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0, a, b, c; j < m; j++) {
            scanf("%d %d %d", &a, &b, &c);
            int k = 2126 * a + 7152 * b + 722 * c;
            r[i][j] = k < 510000 ? 35 : k < 1020000 ? 111 : k < 1530000 ? 43 : k < 2040000 ? 45 : 46;
        }
        r[i][m] = 0;
    }
    for (int i = 0; i < n; i++) {
        printf("%s\n", r[i]);
    }
}
