#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int>> map[801];

void func(int s, int *d) {
    fill(d, d + 800, 1e8);
    priority_queue<pair<int, int>> q;
    q.emplace(0, s);
    d[s] = 0;
    while (!q.empty()) {
        int w = -q.top().first;
        int v = q.top().second;
        q.pop();
        if (d[v] < w) continue;
        for (auto [i, j]: map[v]) {
            if (w + j < d[i]) {
                d[i] = w + j;
                q.emplace(-(w + j), i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, e, a, b, c, d[801], rs, a1, b1;
    cin >> n >> e;
    while (e--) {
        cin >> a >> b >> c;
        map[a].emplace_back(b, c);
        map[b].emplace_back(a, c);
    }
    cin >> a >> b;
    func(a, d);
    rs = d[b];
    func(1, d);
    a1 = d[a];
    b1 = d[b];
    func(n, d);
    a1 += d[b];
    b1 += d[a];
    rs += a1 < b1 ? a1 : b1;
    cout << (rs >= 1e8 ? -1 : rs);
}
