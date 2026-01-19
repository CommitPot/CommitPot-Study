#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    vector<tuple<int, int, int, int> > v;
    cin >> n;
    for (int i = 0, a, b, c; i < n; i++) {
        cin >> a >> b >> c;
        v.emplace_back(a, b, c, i);
    }
    sort(v.begin(), v.end(), [&](auto a, auto b) -> bool {
        auto [a1, b1, c1, d1] = a;
        auto [a2, b2, c2, d2] = b;
        if (a1 != a2) return a1 > a2;
        if (b1 != b2) return b1 < b2;
        return c1 < c2;
    });
    cout << ++get<3>(v[0]);
}
