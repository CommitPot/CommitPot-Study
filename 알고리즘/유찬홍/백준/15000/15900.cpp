#include <iostream>
#include <vector>

using namespace std;

int n, a, b, cnt = 0;
vector<int> map[500001], vis(500001, 0);


void dfs(int v) {
    bool c = false;
    for (int i: map[v]) {
        if (!vis[i]) {
            c = true;
            vis[i] = vis[v] + 1;
            dfs(i);
        }
    }
    if (!c) cnt += vis[v] - 1;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        map[a].emplace_back(b);
        map[b].emplace_back(a);
    }
    vis[1] = 1;
    dfs(1);
    cout << (cnt % 2 ? "Yes" : "No");
}
