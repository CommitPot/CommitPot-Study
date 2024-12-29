#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, k, a, r = -1;
    vector<string> l;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a;
        r = max(r, a);
        l.emplace_back(to_string(a));
    }
    for (int i = 0; i < k - n; i++) {
        l.emplace_back(to_string(r));
    }
    sort(l.begin(), l.end(), [&](const string &a, const string &b) {
        return a + b > b + a;
    });
    for (const auto &i: l) cout << i;
}
