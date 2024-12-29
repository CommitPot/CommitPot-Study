#include <iostream>

using namespace std;

int main() {
    int n, arr[200001], dp[200001];
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    dp[n] = 1;
    for (int i = n - 1; i > 0; i--) {
        if (i + arr[i] + 1 > n) dp[i] = 1;
        else dp[i] = dp[i + arr[i] + 1] + 1;
    }
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
}
