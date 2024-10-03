#include <stdio.h>

int main() {
    int n, m, r = 0, b[2001][2001] = {}, l[2001] = {};
    scanf("%d %d", &n, &m);
    for (int i = 1, a; i <= n; i++) {
        scanf("%d", &b[i][0]);
        for (int j = 1; j <= b[i][0]; j++) scanf("%d", &b[i][j]), l[b[i][j]]++;
    }
    for (int i = 1; i <= n; i++) {
        int x = 1;
        for (int j = 1; j <= b[i][0]; j++) {
            if (l[b[i][j]] == 1) x = 0;
        }
        if (x) r = 1;
    }
    printf("%d", r);
}
