#include <stdio.h>
#include <string.h>

int f(int v) {
    return v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u';
}

int main() {
    int n, r = 1, w = 0, p[2][26] = {};
    char a[2][100001];
    scanf("%d %s %s", &n, a[0], a[1]);
    r &= a[0][0] == a[1][0] && a[0][n - 1] == a[1][n - 1];
    for (int i = 0, j = 0, k = 0; i < n; i++) {
        p[0][a[0][i] - 97]++, p[1][a[1][i] - 97]++;
        if (!f(a[0][i])) a[0][j++] = a[0][i];
        if (!f(a[1][i])) a[1][k++] = a[1][i];
        if (i + 1 == n) a[0][j] = a[1][k] = 0;
    }
    for (int i = 0; i < 26; i++) {
        r &= p[0][i] == p[1][i];
        w += p[0][i];
    }
    printf("%s", !strcmp(a[0], a[1]) && r && w > 1 ? "YES" : "NO");
}
