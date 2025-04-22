#include <stdio.h>

int main() {
    int n, m, r = 0, k = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0, a; i < m; i++) {
        scanf("%d %*d", &a);
        if (n < a) continue;
        r += n - a;
        k = k < n - a ? n - a : k;
    }
    printf("%d", r - k);
}
