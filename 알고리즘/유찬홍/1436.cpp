#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, i = 666;
    cin >> n;
    while (n) {
        string s = to_string(i);
        for (int j = 0; j <= s.size() - 3; j++) {
            if (s[j] == s[j + 1] && s[j] == s[j + 2] && s[j] == '6') {
                n--;
                break;
            }
        }
        i++;
    }
    cout << i - 1;
}
