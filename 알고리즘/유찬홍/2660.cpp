#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, a, b;
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    vector<int> l[n + 1], vis(n + 1, 0), rs, min;
    while (true) {
        cin >> a >> b;
        if (a < 0 && b < 0) break;
        l[a].emplace_back(b);
        l[b].emplace_back(a);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.emplace(i);
        vis[i] = 1;
        int cnt;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int j: l[v]) {
                if (!vis[j]) {
                    vis[j] = vis[v] + 1;
                    q.emplace(j);
                }
            }
            cnt = vis[v];
        }
        for (int &j: vis) j = 0;
        rs.emplace_back(cnt);
    }
    int minV = 1e9;
    for (int i = 0; i < rs.size(); i++) {
        if (minV == rs[i]) min.emplace_back(i + 1);
        if (minV > rs[i]) {
            minV = rs[i];
            min.clear();
            min.emplace_back(i + 1);
        }
    }
    cout << minV - 1 << " " << min.size() << "\n";
    for (int i: min) cout << i << " ";
}
