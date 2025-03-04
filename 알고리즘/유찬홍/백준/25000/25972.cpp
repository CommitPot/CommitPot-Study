#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, r = 1;
    vector<pair<int, int>> l;
    cin >> n;
    for (int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        l.emplace_back(a, b);
    }
    sort(l.begin(), l.end());
    for (int i = 0; i < n - 1; i++) {
        if (l[i].first + l[i].second < l[i + 1].first) r++;
    }
    cout << r;
}
