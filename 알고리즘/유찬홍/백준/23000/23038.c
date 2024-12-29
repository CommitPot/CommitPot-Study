#include <stdio.h>

int main() {
    int n, m;
    char a[901][901];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n * 3; i++) scanf("%s", a[i]);
    for (int i = 0; i < n * 3; i += 3) {
        for (int j = 0; j < m * 3; j += 3) {
            if ((i + j) % 2) {
                int b = 0;
                if (j > 0 && a[i + 1][j - 1] == '#') a[i + 1][j] = '#', b++;
                if (j + 3 < m * 3 && a[i + 1][j + 3] == '#') a[i + 1][j + 2] = '#', b++;
                if (i + 3 < n * 3 && a[i + 3][j + 1] == '#') a[i + 2][j + 1] = '#', b++;
                if (i > 0 && a[i - 1][j + 1] == '#') a[i][j + 1] = '#', b++;
                if (b) a[i + 1][j + 1] = '#';
            }
        }
    }
    for (int i = 0; i < n * 3; i++) printf("%s\n", a[i]);
}
