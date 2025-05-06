#include <math.h>
#include <stdio.h>

int main() {
    int t, n, m, a[524289] = {}, b[100001] = {};
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        int x = pow(2, ceil(log2(n + m)));
        for (int i = x; i < x + n; i++) a[i] = 1;
        for (int i = x + n; i < x * 2; i++) a[i] = 0;
        for (int i = 1; i <= n; i++) b[i] = x + n - i;
        for (int i = x - 1; i > 0; i--) a[i] = a[i * 2] + a[i * 2 + 1];
        for (int i = 0, c, v = x + n - 1; i < m; i++) {
            scanf("%d", &c);
            int j = b[c] * 2, r = n - 1;
            while (j /= 2) if (j % 2) r -= a[j - 1];
            printf("%d ", r);
            j = b[c] * 2;
            while (j /= 2) a[j]--;
            j = ++v * 2;
            while (j /= 2) a[j]++;
            b[c] = v;
        }
        printf("\n");
    }
}
