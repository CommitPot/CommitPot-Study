#include <algorithm>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    bool vis[11][1000001] = {};
    string n;
    int k, r = -1;
    cin >> n >> k;
    queue<pair<int, string>> q;
    q.emplace(k, n);
    while (!q.empty()) {
        auto [a, b] = q.front();
        q.pop();
        if (!a) {
            r = max(r, stoi(b));
            continue;
        }
        for (int i = 0; i < n.size() - 1; i++) {
            for (int j = i + 1; j < n.size(); j++) {
                string c = b;
                if (c[j] == 48 && !i) continue;
                swap(c[i], c[j]);
                int nc = stoi(c);
                if (!vis[a - 1][nc]) {
                    vis[a - 1][nc] = true;
                    q.emplace(a - 1, c);
                }
            }
        }
    }
    cout << r;
}
