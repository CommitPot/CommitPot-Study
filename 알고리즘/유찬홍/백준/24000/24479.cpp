#include <iostream>
#include <algorithm>

using namespace std;

int cnt = 2;

void dfs(vector<int> *list, int *vis, int v) {
    for (int i: list[v]) {
        if (!vis[i]) {
            vis[i] = cnt++;
            dfs(list, vis, i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> list[100001];
    int n, m, r, u, v, vis[100001] = {0};
    cin >> n >> m >> r;
    while (m--) {
        cin >> u >> v;
        list[u].emplace_back(v);
        list[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++) {
        std::sort(list[i].begin(), list[i].end());
    }
    vis[r] = 1;
    dfs(list, vis, r);
    for (int i = 1; i <= n; i++) {
        cout << vis[i] << "\n";
    }
}
