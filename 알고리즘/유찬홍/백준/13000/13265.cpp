#include <vector>
#include <iostream>

using namespace std;

vector<int> l[1001];
int v[1001];

int f(int x, int p) {
    int r = 0;
    for (int u: l[x]) {
        if (u == x) continue;
        if (v[u] < 0) v[u] = !p, r |= f(u, !p);
        else if (v[u] == p) return 1;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t, n, m, r;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        r = 0;
        for (int i = 1; i <= n; i++) l[i].clear(), v[i] = -1;
        for (int i = 0, a, b; i < m; i++) {
            cin >> a >> b;
            l[a].emplace_back(b);
            l[b].emplace_back(a);
        }
        for (int i = 1; i <= n; i++) {
            if (v[i] == -1) v[i] = 0, r |= f(i, 0);
        }
        cout << (r ? "im" : "") << "possible\n";
    }
}
