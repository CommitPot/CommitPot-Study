#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, r, a, b, s = 2;
    cin >> n >> m >> r;
    vector<int> map[n + 1], vis(n + 1, 0);
    queue<int> q;
    while (m--) {
        cin >> a >> b;
        map[a].emplace_back(b);
        map[b].emplace_back(a);
    }
    for (int i = 1; i <= n; i++) sort(map[i].begin(), map[i].end(), greater<int>());
    q.emplace(r);
    vis[r] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i: map[x]) {
            if (!vis[i]) {
                vis[i] = s++;
                q.emplace(i);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << vis[i] << "\n";
    }
}
