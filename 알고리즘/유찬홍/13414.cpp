#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    map<string, int> m;
    string a;
    int k, l;
    cin >> k >> l;
    for (int i = 1; i <= l; i++) {
        cin >> a;
        m[a] = i;
    }
    vector<pair<int, string>> li;
    for (auto &i: m) {
        li.emplace_back(i.second, i.first);
    }
    sort(li.begin(), li.end());
    for (int i = 0; i < k && i < m.size(); i++) {
        cout << li[i].second << "\n";
    }
}
