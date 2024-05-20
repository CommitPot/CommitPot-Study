#include <stdio.h>

typedef long long ll;

int check(int *a, int n, int m) {
    ll s = 0;
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (m < s + a[i]) {
            s = a[i];
            c++;
            if (m < s) return 1e6;
        } else s += a[i];
    }
    return c + (s ? 1 : 0);
}

int main() {
    int n, m, a[100001];
    ll e = 0, s = 1, r = 1e9;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        e += a[i];
    }
    while (s <= e) {
        ll mid = (s + e) / 2;
        int c = check(a, n, mid);
        if (c > m) s = mid + 1;
        else {
            e = mid - 1;
            r = mid < r ? mid : r;
        }
    }
    printf("%lld", r);
}
