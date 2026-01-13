#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, r = 4;
    cin >> n;
    vector<pair<int, int> > l;
    for (int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        l.emplace_back(a, b);
    }
    sort(l.begin(), l.end(), [&](pair<int, int> a, pair<int, int> b) -> bool {
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    });
    while (l[r].first == l[4].first) r++;
    cout << r - 5;
}
