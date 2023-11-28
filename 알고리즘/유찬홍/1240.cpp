#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, a, b, c, vis[1001] = {0};
    cin >> n >> m;
    queue<pair<int, int>> q;
    vector<pair<int, int>> list[n + 1];
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        list[a].emplace_back(b, c);
        list[b].emplace_back(a, c);
    }
    while (m--) {
        cin >> a >> b;
        q.emplace(a, 0);
        vis[a] = 1;
        while (!q.empty()) {
            int v = q.front().first;
            int w = q.front().second;
            if (v == b) {
                cout << w << "\n";
            }
            q.pop();
            for (auto i: list[v]) {
                if (!vis[i.first]) {
                    vis[i.first] = 1;
                    q.emplace(i.first, i.second + w);
                }
            }
        }
        for (int i = 0; i <= n; i++) vis[i] = 0;
    }
}
