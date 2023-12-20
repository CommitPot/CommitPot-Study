#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long int ll;


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    vector<int> a, b, c, d, ab;
    ll a1, b1, c1, d1, n, rs = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a1 >> b1 >> c1 >> d1;
        a.emplace_back(a1);
        b.emplace_back(b1);
        c.emplace_back(c1);
        d.emplace_back(d1);
    }
    for (ll i: a) {
        for (ll j: b) {
            ab.emplace_back(i + j);
        }
    }
    sort(ab.begin(), ab.end());
    for (ll i: c) {
        for (ll j: d) {
            auto s = lower_bound(ab.begin(), ab.end(), -i - j);
            auto e = upper_bound(ab.begin(), ab.end(), -i - j);
            rs += e - s;
        }
    }
    printf("%lld", rs);
}
