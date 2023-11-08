#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    queue<pair<int, int>> q, saveQ;
    string arr[51];
    int n, m, rs = -1, d[] = {0, 1, 0, -1, 0};
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'L') saveQ.emplace(i, j);
        }
    }
    while (!saveQ.empty()) {
        int a = saveQ.front().first;
        int b = saveQ.front().second;
        saveQ.pop();
        int vis[51][51] = {0};
        q.emplace(a, b);
        vis[a][b] = 1;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            int s = 0;
            for (int k = 0; k < 4; k++) {
                int nx = x + d[k];
                int ny = y + d[k + 1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] == 'W' || vis[nx][ny]) continue;
                vis[nx][ny] = vis[x][y] + 1;
                s++;
                q.emplace(nx, ny);
            }
            if (!s && rs < vis[x][y]) rs = vis[x][y];
        }
    }
    cout << rs - 1;
}
