#include <iostream>

using namespace std;

int n, m, s[2001];
short dp[2001][2001];

short f(int x, int y) {
    if (x == y || x > y) return 2;
    if (dp[x][y]) return dp[x][y];
    if (s[x] != s[y]) return 1;
    return dp[x][y] = f(x + 1, y - 1);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string g;
    cin >> n;
    getline(cin, g);
    getline(cin, g);
    int d = 1, e = 0;
    for (char i: g) {
        if (i == ' ') {
            s[d++] = e, e = 0;
        } else e = e * 10 + i - 48;
    }
    s[d++] = e;
    cin >> m;
    g.clear();
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        g += to_string(f(a, b) - 1) + "\n";
    }
    cout << g;
}
