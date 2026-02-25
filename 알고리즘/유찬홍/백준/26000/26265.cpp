#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    typedef pair<string, string> s;
    vector<s> l;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        l.emplace_back(a, b);
    }
    sort(l.begin(), l.end(), [](s a, s b) {
        return a.first == b.first ? a.second > b.second : a.first < b.first;
    });
    for (auto i: l) {
        cout << i.first << " " << i.second << "\n";
    }
}
