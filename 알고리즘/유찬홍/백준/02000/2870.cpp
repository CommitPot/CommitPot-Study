#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    vector<string> w;
    int n;
    cin >> n;
    while (n--) {
        string s, r;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (47 < s[i] && s[i] < 59) {
                if (s[i] == 48 && r.empty() && 47 < s[i + 1] && s[i + 1] < 59) continue;
                r += s[i];
            } else {
                if (!r.empty()) w.push_back(r);
                r.clear();
            }
        }
        if (!r.empty()) w.push_back(r);
    }
    sort(w.begin(), w.end(), [](auto a, auto b) {
        return a.size() == b.size() ? a < b : a.size() < b.size();
    });
    for (auto i: w) cout << i << "\n";
}
