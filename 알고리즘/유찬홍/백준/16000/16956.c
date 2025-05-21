#include <stdio.h>

int main() {
    int n, m, r = 1, d[] = {0, 1, 0, -1};
    char a[250501];
    scanf("%d %d", &n, &m);
    getchar();
    fread(a, 1, n * (m + 1), stdin);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i * m + j + i] == 'S') {
                for (int k = 0; k < 4; k++) {
                    int x = i + d[k], y = j + d[3 - k];
                    if (x < 0 || x >= n || y < 0 || y >= m || a[x * m + y + x] == 'D') continue;
                    if (a[x * m + y + x] == 'W') r = 0;
                    else if (a[x * m + y + x] == '.') a[x * m + y + x] = 'D';
                }
            }
        }
    }
    printf("%d\n", r);
    if (r) fwrite(a, 1, n * (m + 1), stdout);
}
