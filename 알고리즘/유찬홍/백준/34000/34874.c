#include <stdio.h>

int main() {
    int n, m, a[1001][1001] = {}, b[1001];
    scanf("%d %d", &n, &m);
    char s[2001];
    for (int i = 0; i < n; i++) {
        scanf(" %[^\n]", s);
        for (int j = 0; s[j]; j += 2) {
            if (b[i] < s[j] - 48) b[i] = s[j] - 48;
            a[i][j / 2] = s[j] - 48;
        }
    }
    for (int i = 0; i < m; i++) {
        int k = 0;
        for (int j = 0; j < n; j++) k += a[j][i] != b[j];
        printf("%d ", k);
    }
}
