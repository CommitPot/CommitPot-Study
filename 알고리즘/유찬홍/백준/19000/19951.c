#include <stdio.h>

int main() {
    int n, m, a[100001], b[100002] = {};
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0, j, k, l; i < m; i++) {
        scanf("%d %d %d", &j, &k, &l);
        b[j - 1] += l, b[k] += -l;
    }
    for (int i = 1; i < n; i++) b[i] += b[i - 1];
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i] + b[i]);
    }
}
