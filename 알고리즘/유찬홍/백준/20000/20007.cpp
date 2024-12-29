#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, x, y, a, b, c, s = 0, r = 0, o[1001];
    cin >> n >> m >> x >> y;
    vector<pair<int, int>> l[1000];
    for (int i = 0; i < n; i++) o[i] = x + 1;
    priority_queue<pair<int, int>> q;
    while (m--) {
        cin >> a >> b >> c;
        l[a].emplace_back(b, c);
        l[b].emplace_back(a, c);
    }
    q.emplace(0, y);
    o[y] = 0;
    while (!q.empty()) {
        auto [w, v] = q.top();
        q.pop();
        for (auto [i, j]: l[v]) {
            int z = -w + j * 2;
            if (z < o[i]) {
                o[i] = z;
                q.emplace(-z, i);
            }
        }
    }
    sort(o, o + n);
    for (int i = 1; i < n; i++) {
        if (o[i] > x) {
            cout << -1;
            return 0;
        }
        if (s + o[i] > x) s = o[i], r++;
        else s += o[i];
    }
    cout << r + 1;
}
