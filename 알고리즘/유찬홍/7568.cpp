#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, r[51] = {};
    cin >> n;
    vector<pair<int, int>> l;
    for (int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        l.emplace_back(a, b);
    }
    for (int i = 0; i < n; i++) {
        auto [x, y] = l[i];
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            auto [x1, y1] = l[j];
            if (x1 > x && y1 > y) r[i]++;
        }
    }
    for (int i = 0; i < n; i++) cout << r[i] + 1 << " ";
}
