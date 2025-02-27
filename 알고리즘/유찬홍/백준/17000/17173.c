#include <stdio.h>

int main() {
    int n, m, a[1001], r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        int k = 0;
        for (int j = 0; j < m; j++) if (i % a[j] == 0) k = 1;
        if (k) r += i;
    }
    printf("%d", r);
}
