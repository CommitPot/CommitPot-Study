#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    string s;
    unordered_map<string, int> e;
    vector<pair<int, string>> l;
    cin >> n >> m;
    while (n--) {
        cin >> s;
        if (s.length() >= m) e[s]++;
    }
    for (auto [i, j]: e) {
        l.emplace_back(j, i);
    }
    sort(l.begin(), l.end(), [](const pair<int, string> &a, const pair<int, string> &b) -> bool {
        if (a.first != b.first) return a.first > b.first;
        else if (a.second.length() != b.second.size()) return a.second.length() > b.second.size();
        else return a.second < b.second;
    });
    for (const auto &i: l) {
        cout << i.second << "\n";
    }
}
