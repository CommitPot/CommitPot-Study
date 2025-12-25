#include <stdio.h>
#include <string.h>

char s[3072][6145];

void f(int x, int y, int n) {
    if (n == 3) {
        s[x][y] = s[x + 1][y - 1] = s[x + 1][y + 1] = '*';
        for (int i = -2; i < 3; i++) {
            s[x + 2][y + i] = '*';
        }
        return;
    }
    f(x, y, n / 2);
    f(x + n / 2, y - n / 2, n / 2);
    f(x + n / 2, y + n / 2, n / 2);
}

int main() {
    int n;
    memset(s, 32, sizeof(s));
    scanf("%d", &n);
    f(0, n - 1, n);
    for (int i = 0; i < n; i++) {
        s[i][n * 2] = 0;
        printf("%s\n", s[i]);
    }
}
