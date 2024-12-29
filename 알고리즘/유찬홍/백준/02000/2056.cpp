#include <vector>
#include <cstdio>

using namespace std;

int main() {
    int n, r = 0, a[10001], d[10001];
    vector<int> l[10001];
    scanf("%d", &n);
    for (int i = 1, b, c; i <= n; i++) {
        scanf("%d %d", &a[i], &b);
        while (b--) {
            scanf("%d", &c);
            l[i].emplace_back(c);
        }
    }
    for (int i = 1; i <= n; i++) {
        int x = 0;
        for (int j : l[i]) x = max(x, d[j]);
        d[i] = x + a[i];
        r = max(d[i], r);
    }
    printf("%d", r);
}
