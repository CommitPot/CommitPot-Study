#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, w[100001], s[17][100001] = {}, v[100001] = {};
    vector<pair<int, int>> l[100001];
    queue<pair<int, int>> q;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1, a, b, c; i < n; i++) {
        cin >> a >> b >> c;
        l[a].emplace_back(b, c);
        l[b].emplace_back(a, c);
    }
    q.emplace(1, 0);
    while (!q.empty()) {
        auto [x, p] = q.front();
        q.pop();
        for (auto [i, k]: l[x]) {
            if (i == p) continue;
            s[0][i] = x;
            v[i] = v[x] + k;
            q.emplace(i, x);
        }
    }
    for (int i = 1; i < 17; i++) {
        for (int j = 1; j <= n; j++) {
            s[i][j] = s[i - 1][s[i - 1][j]];
        }
    }
    for (int i = 1; i <= n; i++) {
        int k = i;
        for (int j = 16; j >= 0; j--) {
            if (k == 1) break;
            if (!s[j][k]) continue;
            if (w[i] >= v[i] - v[s[j][k]]) k = s[j][k];
        }
        cout << k << '\n';
    }
}
