#include <iostream>

using namespace std;

int f(const string &s, int l, int r) {
    if (l > r) return 0;
    int x = 0, ll = l;
    bool k = false;
    for (int i = l; i <= r; i++) {
        if (s[i] == '(') {
            k = true;
            int y = 0;
            for (int j = i; j <= r; j++) {
                y = s[j] == '(' ? y + 1 : s[j] == ')' ? y - 1 : y;
                if (!y) {
                    if (s[i - 1] != '(') x += i - ll - 1 + (s[i - 1] - 48) * f(s, i + 1, j - 1);
                    i = ll = j + 1;
                    break;
                }
            }
        }
    }
    return k ? x + r - ll + 1 : r - l + 1;
}

int main() {
    string s;
    cin >> s;
    cout << f(s, 0, s.size() - 1);
}
