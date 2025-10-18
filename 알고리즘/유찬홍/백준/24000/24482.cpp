#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> l[100001];
int a[100001];

void f(int v, int w) {
    a[v] = w;
    sort(l[v].begin(), l[v].end(), greater<int>());
    for (int u: l[v]) {
        if (a[u] > -1) continue;
        f(u, w + 1);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, r;
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) a[i] = -1;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        l[u].emplace_back(v);
        l[v].emplace_back(u);
    }
    a[r] = 0;
    f(r, 0);
    for (int i = 1; i <= n; i++) {
        cout << a[i] << "\n";
    }
}
