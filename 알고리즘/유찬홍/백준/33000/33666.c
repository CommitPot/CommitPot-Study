#include <stdio.h>

int main() {
    int n, m, a[1000001], b = 0, c[1000001] = {}, d = 0;
    double p = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > 1) p += a[i], b++;
    }
    p /= b;
    for (int i = 0; i < n; i++) {
        if (a[i] <= p) {
            if (a[i] > m) {
                d = 1;
                break;
            }
            c[a[i]]++;
        }
    }
    if (d) printf("-1");
    else {
        for (int i = m; i > 2; i--) c[i - 1] += c[i];
        for (int i = 1; i <= m; i++) printf("%d ", i == 1 ? n : c[i]);
    }
}
