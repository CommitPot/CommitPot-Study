#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void *a, const void *b) {
    return strcmp(a, b);
}

int main() {
    int n, m, k, a[26] = {};
    char s[300][301], r[90001];
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    for (int i = 0; i < n; i++) {
        qsort(s[i], m, 1, comp);
    }
    qsort(s, n, 301, comp);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            a[s[i][j] - 65]++;
        }
    }
    m = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < a[i]; j++) {
            r[m++] = i + 65;
        }
    }
    r[m] = 0;
    printf("%s", r);
}
