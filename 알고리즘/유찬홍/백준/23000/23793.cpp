#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<long long, int>> l[100001];

void f(int n, int x, long long *d, bool b, int s) {
    fill(d, d + n + 1, 1e18);
    priority_queue<pair<int, int>> q;
    q.emplace(0, x);
    d[x] = 0;
    while (!q.empty()) {
        auto [w, v] = q.top();
        q.pop();
        w = -w;
        if (b && s == v) continue;
        if (d[v] < w) continue;
        for (auto [i, j]: l[v]) {
            if (w + j < d[i]) {
                d[i] = w + j;
                q.emplace(-(w + j), i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, e, a, b, c;
    long long d[100001];
    cin >> n >> e;
    while (e--) {
        cin >> a >> b >> c;
        l[a].emplace_back(b, c);
    }
    cin >> a >> b >> c;
    f(n, a, d, false, 0);
    long long r = d[b];
    f(n, b, d, false, 0);
    cout << (r + d[c] >= 1e18 ? -1 : r + d[c]) << " ";
    for (int i = 1; i <= n; i++) d[i] = 1e18;
    f(n, a, d, true, b);
    cout << (d[c] == 1e18 ? -1 : d[c]);
}
