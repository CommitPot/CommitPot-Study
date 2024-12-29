#include <iostream>
#include <queue>

using namespace std;

vector<int> vis, l[200001];

void dfs(int v) {
    if (l[v].size() == 1) {
        vis[v] = -1;
    }
    for (int i: l[v]) {
        if (vis[i] == 1) {
            vis[i] = 0;
            dfs(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, a, b, c;
    queue<pair<int, int>> q;
    cin >> n;
    vis.assign(n + 1, 1);
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        l[a].emplace_back(b);
        l[b].emplace_back(a);
    }
    cin >> a >> b >> c;
    dfs(1);
    if (vis[a] == -1) {
        cout << "YES";
        return 0;
    }
    vis[a] = 1;
    vis[b] = 2;
    vis[c] = 2;
    q.emplace(a, 1);
    q.emplace(b, 2);
    q.emplace(c, 2);
    while (!q.empty()) {
        auto [v, w] = q.front();
        q.pop();
        if (w == 1 && vis[v] == 2) continue;
        for (int i: l[v]) {
            if (w == 1) {
                if (!vis[i]) {
                    vis[i] = 1;
                    q.emplace(i, 1);
                } else if (vis[i] == -1) {
                    cout << "YES";
                    return 0;
                }
            } else {
                if (vis[i] != 2) {
                    vis[i] = 2;
                    q.emplace(i, 2);
                }
            }
        }
    }
    cout << "NO";
}
