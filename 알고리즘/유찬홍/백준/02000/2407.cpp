#include <iostream>
#include <algorithm>

using namespace std;

string add(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if (a.length() < b.length()) swap(a, b);
    int c, j = 0;
    string d;
    for (int i = 0; i < a.length(); i++) {
        if (b[i] < 48 || b[i] > 58) b += '0';
        c = a[i] + b[i] - 96 + j;
        if (c > 9) {
            c -= 10;
            j = 1;
        } else j = 0;
        d += to_string(c);
    }
    if (j) d += to_string(j);
    reverse(d.begin(), d.end());
    return d;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string dp[102][102];
    int n, m;
    cin >> n >> m;
    dp[0][0] = dp[1][0] = dp[1][1] = "1";
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || i == j) dp[i][j] = "1";
            else dp[i][j] = add(dp[i - 1][j - 1], dp[i - 1][j]);
        }
    }
    cout << dp[n][m];
}
