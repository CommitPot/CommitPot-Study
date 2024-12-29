#include <iostream>

using namespace std;
int n, arr[501][501], dp[501][501], d[] = {0, 1, 0, -1, 0};

int dfs(int x, int y) {
    if (dp[x][y]) return dp[x][y];
    for (int i = 0; i < 4; i++) {
        int nx = x + d[i], ny = y + d[i + 1];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (arr[nx][ny] <= arr[x][y]) continue;
        dp[x][y] = max(dp[x][y], dfs(nx, ny));
    }
    return ++dp[x][y];
}


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    int rs = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rs = max(rs, dfs(i, j));
        }
    }
    cout << rs;
}
