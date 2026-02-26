#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t, n, k;
    string rs;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        string s;
        map<string, int> p;
        int r = 0;
        for (int i = 0; i < n; i++) {
            cin >> s;
            int v = 0;
            for (int j = 0; j < k; j++) {
                if (s[j] < 97) v++, s[j] += 32;
            }
            sort(s.begin(), s.end());
            p[s + to_string(v)]++;
        }
        for (auto [i, j]: p) r += j * (j - 1) / 2;
        rs += to_string(r) + "\n";
    }
    cout << rs;
}
