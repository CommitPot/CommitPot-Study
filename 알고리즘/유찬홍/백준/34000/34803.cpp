#include <map>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int l, n, k;
    string s[20];
    map<string, int> mp;
    cin >> l >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    cin >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s[i].size() - k + 1; j++) {
            mp[s[i].substr(j, k)]++;
        }
    }
    int r = 0;
    for (auto [_, v]: mp) r = max(r, v);
    cout << r;
}
