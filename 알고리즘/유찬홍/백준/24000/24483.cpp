#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> l[100001];
long long rs[100001], k = 2;

void f(int v, int d) {
    for (int u: l[v]) {
        if (rs[u]) continue;
        rs[u] = d * k++;
        f(u, d + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, m, r;
    long long s = 0;
    cin >> n >> m >> r;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        l[u].emplace_back(v);
        l[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++) sort(l[i].begin(), l[i].end());
    rs[r] = 1;
    f(r, 1);
    for (int i = 1; i <= n; i++) s += rs[i];
    cout << s - rs[r];
}
