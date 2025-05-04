#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct T {
    int v, s;
} T;

int c(const void *a, const void *b) {
    return ((T *) a)->v - (((T *) b)->v);
}

int main() {
    int n, t[262144] = {}, l = 1;
    long long r[100000], k = 0;
    T a[100001];
    scanf("%d", &n);
    int g = pow(2, ceil(log2(n)));
    for (int i = g; i < g + n; i++) t[i] = 1;
    for (int i = g - 1; i > 0; i--) t[i] = t[i * 2] + t[i * 2 + 1];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].v);
        a[i].s = i;
    }
    qsort(a, n, 8, c);
    for (int i = 0; i < n;) {
        while (l < a[i].v) l++, k += t[1];
        int p = 0, m, b = t[1];
        do {
            int j = a[i].s + g;
            m = 1;
            while (j) {
                if (j % 2) m += t[j - 1];
                j /= 2;
            }
            r[a[i].s] = k + m;
            i++, p++;
        } while (i != n && a[i].v == a[i - 1].v);
        for (int q = i - p; q < i; q++) {
            int j = a[q].s + g;
            while (j) {
                t[j]--;
                j /= 2;
            }
        }
        k += b, l++;
    }
    for (int i = 0; i < n; i++) printf("%lld\n", r[i]);
}
