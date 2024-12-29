#include <iostream>
#include <vector>

using namespace std;

vector<int> l[501];
bool vis[501];

bool dfs(int v, int p) {
    if (vis[v]) return true;
    vis[v] = true;
    for (int i: l[v]) {
        if (i != p && dfs(i, v)) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, a, b, c = 1;
    cin >> n >> m;
    while (n | m) {
        int cnt = 0;
        while (m--) {
            cin >> a >> b;
            l[a].emplace_back(b);
            l[b].emplace_back(a);
        }
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && !dfs(i, -1)) cnt++;
        }
        cout << "Case " << c++ << ": ";
        switch (cnt) {
            case 0:
                cout << "No trees";
                break;
            case 1:
                cout << "There is one tree";
                break;
            default:
                cout << "A forest of " << cnt << " trees";
                break;
        }
        cout << ".\n";
        for (int i = 1; i <= n; i++) l[i].clear(), vis[i] = false;
        cin >> n >> m;
    }
}
