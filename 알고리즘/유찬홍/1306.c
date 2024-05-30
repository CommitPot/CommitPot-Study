#include <stdio.h>

int a[1000001], st[2100001];

int max(int x, int y) {
    return x > y ? x : y;
}

int init(int s, int e, int n) {
    if (s == e) return st[n] = a[s];
    int mid = (s + e) / 2;
    return st[n] = max(init(s, mid, n * 2), init(mid + 1, e, n * 2 + 1));
}

int find(int s, int e, int l, int r, int n) {
    if (e < l || r < s) return 0;
    if (l <= s && e <= r) return st[n];
    int mid = (s + e) / 2;
    return max(find(s, mid, l, r, n * 2), find(mid + 1, e, l, r, n * 2 + 1));
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    init(1, n, 1);
    for (int i = m; i <= n - m + 1; i++) {
        printf("%d ", find(1, n, i - m + 1, i + m - 1, 1));
    }
}
