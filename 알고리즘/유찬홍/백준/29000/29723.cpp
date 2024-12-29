#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m, k, r = 0, r1;
    map<string, int> a;
    cin >> n >> m >> k;
    while (n--) {
        string s;
        int b;
        cin >> s >> b;
        a[s] = b;
    }
    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;
        r += a[s];
        a.erase(s);
    }
    r1 = r;
    vector<int> v;
    for (auto i: a) v.emplace_back(i.second);
    sort(v.begin(), v.end());
    for (int i = 0; i < m - k; i++) r += v[i];
    for (int i = v.size() - m + k; i < v.size(); i++) r1 += v[i];
    cout << r << ' ' << r1;
}
