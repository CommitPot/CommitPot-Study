#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

string map[51];
int n, m, rs = -1, d[] = {0, 1, 0, -1, 0};
bool vis[51][51][2][2][2][2][2][2];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    queue<tuple<int, int, int, int, int, int, int, int, int>> q;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> map[i];
        int len = map[i].length();
        for (int j = 0; j < len; j++) {
            if (map[i][j] == 48) {
                vis[i][j][0][0][0][0][0][0] = true;
                q.emplace(i, j, 0, 0, 0, 0, 0, 0, 1);
            }
        }
    }
    while (!q.empty()) {
        auto [x, y, ak, bk, ck, dk, ek, fk, c] = q.front();
        if (map[x][y] == 49) {
            rs = c - 1;
            break;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i], ny = y + d[i + 1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == '#' ||
                vis[nx][ny][ak][bk][ck][dk][ek][fk])
                continue;
            if (map[nx][ny] == '.' || (map[nx][ny] > 47 && map[nx][ny] < 50)) {
                vis[nx][ny][ak][bk][ck][dk][ek][fk] = true;
                q.emplace(nx, ny, ak, bk, ck, dk, ek, fk, c + 1);
            }
            if ((map[nx][ny] == 65 && ak) || (map[nx][ny] == 97)) {
                vis[nx][ny][1][bk][ck][dk][ek][fk] = true;
                q.emplace(nx, ny, 1, bk, ck, dk, ek, fk, c + 1);
            }
            if ((map[nx][ny] == 66 && bk) || (map[nx][ny] == 98)) {
                vis[nx][ny][ak][1][ck][dk][ek][fk] = true;
                q.emplace(nx, ny, ak, 1, ck, dk, ek, fk, c + 1);
            }
            if ((map[nx][ny] == 67 && ck) || (map[nx][ny] == 99)) {
                vis[nx][ny][ak][bk][1][dk][ek][fk] = true;
                q.emplace(nx, ny, ak, bk, 1, dk, ek, fk, c + 1);
            }
            if ((map[nx][ny] == 68 && dk) || (map[nx][ny] == 100)) {
                vis[nx][ny][ak][bk][ck][1][ek][fk] = true;
                q.emplace(nx, ny, ak, bk, ck, 1, ek, fk, c + 1);
            }
            if ((map[nx][ny] == 69 && ek) || (map[nx][ny] == 101)) {
                vis[nx][ny][ak][bk][ck][dk][1][fk] = true;
                q.emplace(nx, ny, ak, bk, ck, dk, 1, fk, c + 1);
            }
            if ((map[nx][ny] == 70 && fk) || (map[nx][ny] == 102)) {
                vis[nx][ny][ak][bk][ck][dk][ek][1] = true;
                q.emplace(nx, ny, ak, bk, ck, dk, ek, 1, c + 1);
            }
        }
    }
    cout << rs;
}
