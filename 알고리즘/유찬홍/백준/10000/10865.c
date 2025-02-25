#include <stdio.h>

int main() {
    int n, m, r[100001] = {};
    scanf("%d %d", &n, &m);
    for (int i = 0, a, b; i < m; i++) {
        scanf("%d %d", &a, &b);
        r[a]++;
        r[b]++;
    }
    for (int i = 0; i < n; i++) {
        printf("%d\n", r[i + 1]);
    }
}
