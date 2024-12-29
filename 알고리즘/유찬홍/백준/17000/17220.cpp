#include <vector>
#include <iostream>

using namespace std;

bool vis[27];
vector<int> map[27], r_map[27];

void dfs(int v) {
    for (int i: map[v]) {
        if (!vis[i]) {
            vis[i] = true;
            dfs(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, cnt = 0;
    char a, b;
    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        r_map[b - 65].emplace_back(a - 65);
        map[a - 65].emplace_back(b - 65);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a;
        vis[a - 65] = true;
    }
    for (int i = 0; i < n; i++) if (r_map[i].empty() && !vis[i]) dfs(i);
    for (int i = 0; i < n; i++) if (vis[i]) cnt++;
    cout << cnt - m;
}
