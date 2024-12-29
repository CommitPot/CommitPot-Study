#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    while (n--) {
        string s, s1;
        cin >> s;
        for (int i = 0, j = m - 1; i < j; i++, j--) {
            if (s[i] != '.') s1 += s[i];
            else if (s[j] != '.') s1 += s[j];
            else s1 += '.';
        }
        cout << s1;
        reverse(s1.begin(), s1.end());
        cout << s1 << "\n";
    }
}
