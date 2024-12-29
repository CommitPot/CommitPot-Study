#include <iostream>
#include <algorithm>

using namespace std;

bool func(const string &a, const string &b) {
    return (a + b) > (b + a);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++) cin >> s[i];
    sort(s, s + n, func);
    if (s[0] == "0") {
        cout << 0;
        return 0;
    }
    for (const auto &i: s) cout << i;
}
