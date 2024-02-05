#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, c, a;
    map<int, pair<int, int>> m;
    priority_queue<tuple<int, int, int>> q;
    cin >> n >> c;
    while (n--) {
        cin >> a;
        if (m.find(a) == m.end()) m[a] = {1, n};
        else m[a].first++;
    }
    for (auto [k, v]: m) {
        q.emplace(v.first, v.second, k);
    }
    while (!q.empty()) {
        auto [v, w, k] = q.top();
        q.pop();
        while (v--) cout << k << " ";
    }
}
