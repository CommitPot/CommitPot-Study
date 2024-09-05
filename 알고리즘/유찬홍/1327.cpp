#include <queue>
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, k, rs = -1;
    string s;
    queue<string> q;
    unordered_map<string, int> m;
    cin >> n >> k;
    for (int i = 0, a; i < n; i++) cin >> a, s += a + 48;
    q.emplace(s);
    m[s] = 0;
    while (!q.empty()) {
        auto x = q.front();
        bool f = true;
        for (int i = 1; i < n; i++) if (x[i] < x[i - 1]) f = false;
        if (f) {
            rs = m[x];
            break;
        }
        q.pop();
        for (int i = 0; i <= n - k; i++) {
            string r = x;
            for (int j = i, l = k - 1 + i; j < l; j++, l--) swap(r[j], r[l]);
            if (m.find(r) == m.end()) {
                m[r] = m[x] + 1;
                q.emplace(r);
            }
        }
    }
    cout << rs;
}
