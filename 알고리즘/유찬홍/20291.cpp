#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    map<string, int> m;
    int n;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        int d = 0;
        for (char i: s) {
            d++;
            if (i == '.') break;
        }
        int len = s.length();
        string s1;
        for (int i = d; i < len; i++) s1 += s[i];
        m[s1]++;
    }
    for (const auto &i: m) cout << i.first << " " << i.second << "\n";
}
