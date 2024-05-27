#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, q, a[1001] = {}, d = 0;
    scanf("%d %d %d", &n, &q, &d);
    a[1] = 0;
    for (int i = 2, b; i <= n; i++) {
        scanf("%d", &b);
        a[i] += abs(b - d) + a[i - 1];
        d = b;
    }
    while (q--) {
        int b, c;
        scanf("%d %d", &b, &c);
        printf("%d\n", a[c] - a[b]);
    }
}
