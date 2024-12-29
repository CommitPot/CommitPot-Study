#include <stdio.h>

int main() {
    int n, m, s[101];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
    scanf("%d", &m);
    for (int i = 0, j, k; i < m; i++) {
        scanf("%d %d", &j, &k);
        if (j == 1) {
            for (int l = k; l <= n; l += k) s[l] = !s[l];
        } else {
            s[k] = !s[k];
            for (int l = k - 1, o = k + 1; l > 0 && o <= n && s[l] == s[o]; l--, o++) s[l] = !s[l], s[o] = !s[o];
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", s[i]);
        if (i % 20 == 0) printf("\n");
    }
}
