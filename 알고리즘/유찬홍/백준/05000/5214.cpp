#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, k, m;
    bool vis[101001];
    string s;
    vector<int> l[101001];
    cin >> n >> k >> m;
    getline(cin, s);
    for (int i = 1; i <= m; i++) {
        getline(cin, s);
        int c = 0;
        for (char j: s) {
            if (j == ' ') {
                l[n + i].emplace_back(c);
                l[c].emplace_back(n + i);
                c = 0;
            } else c = c * 10 + j - 48;
        }
        l[n + i].emplace_back(c);
        l[c].emplace_back(n + i);
    }
    queue<pair<int, int>> q;
    vis[1] = true;
    q.emplace(1, 1);
    while (!q.empty()) {
        auto [x, w] = q.front();
        if (x == n) {
            cout << w / 2 + 1;
            return 0;
        }
        q.pop();
        for (int i: l[x]) {
            if (!vis[i]) {
                vis[i] = true;
                q.emplace(i, w + 1);
            }
        }
    }
    cout << -1;
}
