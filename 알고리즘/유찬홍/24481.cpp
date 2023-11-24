#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int *vis, const vector<int> *list, int x, int depth) {
    for (int i: list[x]) {
        if (!vis[i]) {
            vis[i] = depth;
            dfs(vis, list, i, depth + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, r, u, v, vis[100001] = {0};
    cin >> n >> m >> r;
    vector<int> list[n + 1];
    while (m--) {
        cin >> u >> v;
        list[u].emplace_back(v);
        list[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++) {
        std::sort(list[i].begin(), list[i].end());
    }
    vis[r] = 1;
    dfs(vis, list, r, 2);
    for (int i = 1; i <= n; i++) {
        cout << vis[i] - 1 << "\n";
    }
}
