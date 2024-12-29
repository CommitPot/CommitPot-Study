#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int c;
bool vis[10001];
vector<int> l[10001];

void dfs(int v) {
    c++;
    for (int i: l[v]) {
        if (!vis[i]) {
            vis[i] = true;
            dfs(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        l[b].emplace_back(a);
    }
    int r = 0;
    vector<int> rs;
    for (int i = 1; i <= n; i++) {
        vis[i] = true;
        dfs(i);
        for (int j = 1; j <= n; j++) vis[j] = false;
        if (r <= c) {
            if (r == c) rs.emplace_back(i);
            else {
                rs.clear();
                rs.emplace_back(i);
                r = c;
            }
        }
        c = 0;
    }
    sort(rs.begin(), rs.end());
    for (int i: rs) cout << i << " ";
}
