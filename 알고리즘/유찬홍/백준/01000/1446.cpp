#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, a, b, c, d, dp[10001];
    cin >> n >> d;
    tuple<int, int, int> e[12];
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        e[i] = {a, b, c};
    }
    dp[0] = 0;
    for (int i = 1; i <= d; i++) {
        dp[i] = dp[i - 1] + 1;
        for (auto [x, y, z]: e) {
            if (y == i) dp[i] = min(dp[i], dp[x] + z);
        }
    }
    cout << dp[d];
}
