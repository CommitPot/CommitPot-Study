#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int dp[5001];
    for (int &i: dp) i = -1;
    string s;
    cin >> s;
    function<int(int a, int b)> f = [&](int a, int b) {
        int l = b - a + 1;
        if (!l) return 1;
        if (s[a] == 48) return 0;
        if (dp[l] != -1) return dp[l];
        dp[l] = f(a + 1, b);
        if (l > 1) {
            int c = (s[a] - 48) * 10 + s[a + 1] - 48;
            if (c >= 1 && c <= 26) dp[l] = (dp[l] + f(a + 2, b)) % 1000000;
        }
        return dp[l];
    };
    cout << f(0, s.size() - 1);
}
