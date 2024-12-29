#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> node;
vector<bool> vis;
vector<int> p, d, c;

void dfs(int x, int depth) {
    vis[x] = true;
    d[x] = depth;
    for (int i: node[x]) {
        if (vis[i]) continue;
        p[i] = x;
        dfs(i, depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t, n, a, b;
    cin >> t;
    while (t--) {
        cin >> n;
        c.assign(n + 1, 0);
        node.assign(n + 1, vector<int>());
        vis.assign(n + 1, false);
        p.assign(n + 1, 0), d.assign(n + 1, 0);
        for (int i = 1; i < n; i++) {
            cin >> a >> b;
            node[a].push_back(b);
            node[b].push_back(a);
            c[b]++;
        }
        for (int i = 1; i <= n; i++) {
            if (!c[i]) dfs(i, 0);
        }
        cin >> a >> b;
        while (d[a] != d[b]) {
            if (d[a] > d[b]) a = p[a];
            else b = p[b];
        }
        while (a != b) {
            a = p[a];
            b = p[b];
        }
        cout << a << "\n";
    }
}
