#include <stdio.h>

int main() {
    int r, c, d[][2] = {{0,  1},
                        {0,  -1},
                        {1,  0},
                        {1,  1},
                        {1,  -1},
                        {-1, 0},
                        {-1, 1},
                        {-1, -1}};
    char m[100][101];
    while (scanf("%d %d", &r, &c)) {
        if (!r) break;
        int f = 0;
        char e[10100];
        for (int i = 0; i < r; i++) scanf("%s", m[i]);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (m[i][j] == '*') {
                    e[f++] = '*';
                    continue;
                }
                int b = 0;
                for (int k = 0; k < 8; k++) {
                    int nx = i + d[k][0], ny = j + d[k][1];
                    if (nx < 0 || nx >= r || ny < 0 || ny >= c || m[nx][ny] == '.') continue;
                    b++;
                }
                e[f++] = b + 48;
            }
            e[f++] = '\n';
        }
        e[f++] = 0;
        printf("%s", e);
    }
}
