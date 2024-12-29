#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int p[100001];

int f(int v) { return p[v] = p[v] == v ? v : f(p[v]); }

void u(int a, int b) {
    a = f(a), b = f(b);
    p[max(a, b)] = min(a, b);
}

int main() {
    int n, q;
    vector<tuple<int, int, int>> m;
    scanf("%d %d", &n, &q);
    for (int i = 1, a, b, c; i <= n; i++) {
        p[i] = i;
        scanf("%d %d %d", &a, &b, &c);
        m.emplace_back(a, b, i);
    }
    sort(m.begin(), m.end());
    auto [a, b, c] = m[0];
    for (int i = 1; i < m.size(); i++) {
        auto [d, e, f] = m[i];
        if (b >= d) u(c, f);
        if (b < e) a = d, b = e, c = f;
    }
    char d[200010];
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &a, &b);
        d[i * 2] = (char) ((f(a) == f(b)) + 48);
        d[i * 2 + 1] = '\n';
    }
    d[(q - 1) * 2 + 1] = 0;
    printf("%s", d);
}
