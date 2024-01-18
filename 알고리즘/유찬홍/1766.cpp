#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, a, b;
    vector<pair<int, int>> arr;
    priority_queue<pair<int, int>> q;
    cin >> n >> m;
    vector<int> graph[n + 1];
    vector<int> ind(n + 1, 0);
    while (m--) {
        cin >> a >> b;
        graph[a].emplace_back(b);
        ind[b]++;
    }
    for (int i = 1; i <= n; i++) if (!ind[i]) q.emplace(-i, 1);
    while (!q.empty()) {
        auto [v, p] = q.top();
        q.pop();
        v *= -1;
        arr.emplace_back(v, p);
        for (auto i: graph[v]) {
            if (!--ind[i]) q.emplace(-i, p + 1);
        }
    }
    for (auto i: arr) cout << i.first << " ";
}
