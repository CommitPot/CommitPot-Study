#include <stdio.h>

int n, a[1000001];

long long g(int s, int m, int e) {
    int i = s, j = m + 1, k = 0, t[e - s + 1];
    long long r = 0;

    while (i <= m && j <= e) {
        if (a[i] < a[j]) t[k++] = a[i++];
        else r += m - i + 1, t[k++] = a[j++];
    }

    while (i <= m) t[k++] = a[i++];
    while (j <= e) t[k++] = a[j++];

    for (i = s, k = 0; i <= e; i++, k++) a[i] = t[k];
    return r;
}

long long f(int s, int e) {
    long long r = 0;
    if (s < e) {
        int m = (s + e) / 2;
        r += f(s, m);
        r += f(m + 1, e);
        r += g(s, m, e);
    }
    return r;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("%lld", f(0, n - 1));
}
