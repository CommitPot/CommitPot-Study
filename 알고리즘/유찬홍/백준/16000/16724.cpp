#include <iostream>

using namespace std;
int n, m, vis[1001][1001];
string map[1001];

bool check(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

void dfs(int x, int y, int a) {
    if (check(x, y)) return;
    if (!vis[x][y]) {
        vis[x][y] = a;
        switch (map[x][y]) {
            case 'U':
                dfs(x - 1, y, a);
                break;
            case 'D':
                dfs(x + 1, y, a);
                break;
            case 'L':
                dfs(x, y - 1, a);
                break;
            case 'R':
                dfs(x, y + 1, a);
                break;
        }
        if (!check(x + 1, y) && map[x + 1][y] == 'U') dfs(x + 1, y, a);
        if (!check(x - 1, y) && map[x - 1][y] == 'D') dfs(x - 1, y, a);
        if (!check(x, y + 1) && map[x][y + 1] == 'L') dfs(x, y + 1, a);
        if (!check(x, y - 1) && map[x][y - 1] == 'R') dfs(x, y - 1, a);
    }
}

int main() {
    int c = 1;
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> map[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) {
                dfs(i, j, c++);
            }
        }
    }
    cout << c - 1;
}
