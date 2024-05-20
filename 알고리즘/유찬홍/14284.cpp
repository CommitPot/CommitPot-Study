#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, a, b, c, m;
    cin >> n >> m;
    vector<pair<int, int>> l[5001];
    int w[5001];
    for (int i = 1; i <= n; i++) w[i] = 1e9;
    priority_queue<pair<int, int>> q;
    while (m--) {
        cin >> a >> b >> c;
        l[a].emplace_back(b, c);
        l[b].emplace_back(a, c);
    }
    cin >> a >> b;
    q.emplace(0, a);
    w[a] = 0;
    while (!q.empty()) {
        auto [d, e] = q.top();
        q.pop();
        for (auto [f, g]: l[e]) {
            if (g - d < w[f]) {
                w[f] = g - d;
                q.emplace(-w[f], f);
            }
        }
    }
    cout << w[b];
}
