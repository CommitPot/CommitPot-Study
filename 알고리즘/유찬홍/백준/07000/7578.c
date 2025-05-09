#include <stdio.h>

long long g(int s, int m, int e, int *t) {
    int i = s, j = m + 1, k = 0, p[e - s + 1];
    long long r = 0;
    while (i <= m && j <= e) {
        if (t[i] < t[j]) p[k++] = t[i++];
        else r += m - i + 1, p[k++] = t[j++];
    }

    while (i <= m) p[k++] = t[i++];
    while (j <= e) p[k++] = t[j++];

    for (int l = s; l <= e; l++) t[l] = p[l - s];

    return r;
}

long long f(int s, int e, int *t) {
    if (s < e) {
        int m = (s + e) / 2;
        return f(s, m, t) + f(m + 1, e, t) + g(s, m, e, t);
    }

    return 0;
}

int main() {
    int n, a[1000001] = {}, t[500001];
    scanf("%d", &n);
    for (int i = 0, j; i < n; i++) {
        scanf("%d", &j);
        a[j] = i;
    }
    for (int i = 0, j; i < n; i++) {
        scanf("%d", &j);
        t[i] = a[j];
    }
    printf("%lld", f(0, n - 1, t));
}
