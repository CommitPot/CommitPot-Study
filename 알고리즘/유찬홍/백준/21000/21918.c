#include <stdio.h>

int main() {
    int n, m;
    char r[8001];
    scanf("%d %d %[^\n] ", &n, &m, &r[1]);
    for (int i = 0, a, b, c; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1) r[b * 2 - 1] = c + 48;
        else {
            for (int j = b; j <= c; j++) r[j * 2 - 1] = a == 2 ? !(r[j * 2 - 1] - 48) + 48 : (a == 4) + 48;
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%c ", r[i * 2 - 1]);
    }
}
