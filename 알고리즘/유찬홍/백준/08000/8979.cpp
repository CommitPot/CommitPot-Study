#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    vector<tuple<int, int, int, int> > l;
    int n, k;
    cin >> n >> k;
    for (int i = 0, a, b, c, d; i < n; i++) {
        cin >> a >> b >> c >> d;
        l.emplace_back(b, c, d, a);
    }
    sort(l.begin(), l.end(), greater<tuple<int, int, int, int> >());
    for (int i = 1, j = 1, m = 0; i < n; i++) {
        auto [a, b, c, d] = l[i];
        auto [a1, b1, c1, d1] = l[i - 1];
        if (a == a1 && b == b1 && c == c1) m++;
        else j += m + 1, m = 0;
        if (d == k) {
            cout << j;
            return 0;
        }
    }
    cout << 1;
}
