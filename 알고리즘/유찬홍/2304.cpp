#include <algorithm>
#include <iostream>
#include <vector>

#define x first
#define y second
#define pi pair<int, int>
using namespace std;


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, f, g = 0, rs = 0;
    cin >> n;
    pi r;
    vector<pi > l(n), s, s1;
    for (int i = 0; i < n; i++) cin >> l[i].x >> l[i].y;
    sort(l.begin(), l.end());
    for (int i = 0; i < n; i++) {
        if (g < l[i].y) {
            g = l[i].y;
            f = i;
            r = l[i];
        }
    }
    for (int i = 0; i < f; i++) {
        if (s.empty() || s.back().y < l[i].y) s.emplace_back(l[i]);
    }
    for (int i = n - 1; i > f; i--) {
        if (s1.empty() || s1.back().y < l[i].y) s1.emplace_back(l[i]);
    }
    if (!s.empty())
        for (int i = 0; i < s.size() - 1; i++) {
            auto [a, b] = s[i];
            rs += (s[i + 1].x - a) * b;
        }
    if (!s1.empty())
        for (int i = 0; i < s1.size() - 1; i++) {
            auto [a, b] = s1[i];
            rs += (a - s1[i + 1].x) * b;
        }
    if (!s.empty()) rs += (r.x - s.back().x) * s.back().y;
    if (!s1.empty()) rs += (s1.back().x - r.x) * s1.back().y;
    cout << rs + r.y;
}
