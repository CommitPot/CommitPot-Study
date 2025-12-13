#include <unordered_map>
#include <set>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    char a;
    string s;
    set<int> t;
    vector<string> v;
    unordered_map<string, int> mp;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int j = 0, l = 0;
        for (int k = 0; k < m; k++) {
            cin >> a;
            if (a == '.') l++;
            else j = j < l ? l : j, l = 0;
        }
        cin >> s;
        v.emplace_back(s);
        j = j < l ? l : j;
        mp[s] = j;
        t.insert(j);
    }
    cout << t.size() << '\n';
    for (auto k: v) {
        cout << mp[k] << ' ' << k << '\n';
    }
}
