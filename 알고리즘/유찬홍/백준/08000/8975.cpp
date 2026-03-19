#include <set>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t, n, r = 0, i;
    set<string> s;
    cin >> t;
    string a;
    for (i = 0; i < t; i++) cin >> a, s.insert(a);
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a;
        if (s.find(a) != s.end()) r++, s.erase(a);
        if (r >= (t + 1) / 2) break;
    }
    cout << i + 1;
}
