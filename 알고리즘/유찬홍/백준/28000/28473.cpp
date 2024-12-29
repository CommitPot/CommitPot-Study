#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
vector<int> p;

int f(int x) { return p[x] = p[x] == x ? x : f(p[x]); }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, in[4];
    long long int v = 0;
    priority_queue<tuple<int, int, int, int>> q;
    vector<int> rs;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) p.emplace_back(i);
    while (m--) {
        for (int &i: in) {
            cin >> i;
        }
        q.emplace(-in[2], -in[3], in[0], in[1]);
    }
    while (!q.empty()) {
        auto [z, w, x, y] = q.top();
        q.pop();
        x = f(x), y = f(y);
        if (x == y) continue;
        p[max(x, y)] = min(x, y);
        rs.emplace_back(-z);
        v += -w, m++;
    }
    if (m == n - 2) {
        sort(rs.begin(), rs.end());
        for (int i: rs) {
            cout << i;
        }
        cout << " " << v;
    } else cout << -1;
}
