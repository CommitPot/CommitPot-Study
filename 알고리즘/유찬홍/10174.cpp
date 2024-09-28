#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    string s;
    cin >> n;
    getline(cin, s);
    while (n--) {
        getline(cin, s);
        bool r = false;
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if (s[i] > 64 && s[i] < 91) s[i] += 32;
            if (s[j] > 64 && s[j] < 91) s[j] += 32;
            if (s[i] != s[j]) r = true;
        }
        cout << (r ? "No" : "Yes") << '\n';
    }
}
