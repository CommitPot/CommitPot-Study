#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    vector<pair<int, int> > l, p;
    int n, a, b, i = 0, c = 0, r = 0;
    cin >> n;
    while (i++ < n) {
        cin >> a >> b;
        l.emplace_back(-i, a);
        l.emplace_back(i, b);
    }
    sort(l.begin(), l.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) return a.first > b.first;
        return a.first != b.first ? a.second < b.second : a.first > b.first;
    });
    for (auto [v, w]: l) {
        if (v < 0) {
            c++;
            if (r <= c) {
                if (r < c) r = c, p.clear();
                p.emplace_back(v, w);
            }
        } else {
            if (r <= c--) p.emplace_back(v, w);
        }
    }
    cout << r << "\n";
    a = b = -1;
    for (i = 0; i < p.size(); i++) {
        if (a < 0) a = p[i].second;
        else {
            if (p[i].second == b) {
                b = -1;
                continue;
            } else if (b > -1 && p[i].second != b) break;
            b = p[i].second;
        }
    }
    cout << a << " " << b;
}
