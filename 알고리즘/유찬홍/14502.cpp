#include <iostream>
#include <vector>
#include <queue>

using namespace std;
queue<pair<int, int>> q;
vector<pair<int, int>> arr;
int n, m, rs = 0, map[8][8], test_map[8][8], d[] = {0, 1, 0, -1, 0};

void bt(int cnt) {
    if (cnt == 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                test_map[i][j] = map[i][j];
            }
        }
        for (auto i: arr) {
            q.emplace(i);
        }
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int dx = d[i] + x;
                int dy = d[i + 1] + y;
                if (dx < 0 || dx >= n || dy < 0 || dy >= m || test_map[dx][dy] != 0) continue;
                test_map[dx][dy] = 2;
                q.emplace(dx, dy);
            }
        }
        int z = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!test_map[i][j]) z++;
            }
        }
        if (z > rs) rs = z;
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!map[i][j]) {
                map[i][j] = 1;
                bt(cnt + 1);
                map[i][j] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) arr.emplace_back(i, j);
        }
    }
    bt(0);
    cout << rs;
}
