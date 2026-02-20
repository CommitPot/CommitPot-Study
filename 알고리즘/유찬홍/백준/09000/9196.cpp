#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    pair<int, int> l[11175];
    int r = 0, a, b;
    for (int i = 0; i < 150; i++) {
        for (int j = i + 1; j < 150; j++) {
            l[r++] = {i + 1, j + 1};
        }
    }
    sort(l, l + r, [](pair<int, int> a, pair<int, int> b) -> bool {
        int c = pow(a.first, 2) + pow(a.second, 2), d = pow(b.first, 2) + pow(b.second, 2);
        return c == d ? a.first < b.first : c < d;
    });
    while (cin >> a >> b, a) {
        for (int i = 0; i < r; i++) {
            if (l[i].first == a && l[i].second == b) {
                cout << l[i + 1].first << " " << l[i + 1].second << "\n";
                break;
            }
        }
    }
}
