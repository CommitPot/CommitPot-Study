#include <set>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, dp[101] = {};
    string a, b;
    set<string> s;
    cin >> a >> n;
    for (int i = 0; i < n; i++) {
        cin >> b, s.insert(b);
    }
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < i; j++) {
            dp[i] |= dp[j] ? s.find(a.substr(j + 1, i - j)) != s.end() : 0;
        }
        dp[i] |= s.find(a.substr(0, i + 1)) != s.end();
    }
    cout << dp[a.size() - 1];
}
