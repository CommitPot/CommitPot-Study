#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t, n;
    vector<int> ind, l[100001];
    vector<pair<int, int>> rs;
    priority_queue<pair<int, int>> q;
    cin >> t;
    while (t--) {
        cin >> n;
        ind.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> l[i].emplace_back(), ind[l[i][l[i].size() - 1]]++;
        for (int i = 1; i <= n; i++) if (!ind[i]) q.emplace(-i, 1);
        while (!q.empty()) {
            auto [v, p] = q.top();
            q.pop();
            rs.emplace_back(-v, p);
            for (int i: l[-v]) {
                if (!--ind[i]) q.emplace(-i, p + 1);
            }
        }
        cout << rs.size() << "\n";
        rs.clear();
        ind.clear();
        for (int i = 1; i <= n; i++) l[i].clear();
    }
}
