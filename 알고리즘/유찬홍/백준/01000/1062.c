#include <stdio.h>

int r = 0, n;
char p[50][8], a[27] = "10100000100001000001000000";

void f(int v, int o) {
    if (!o) {
        int q = 0;
        for (int i = 0; i < n; i++) {
            int u = 1;
            for (int j = 0; p[i][j]; j++) {
                if (a[p[i][j] - 97] == '0') u = 0;
            }
            if (u) q++;
        }
        if (r < q) r = q;
        return;
    }
    if (v > 25 || o < 0) return;
    f(v + 1, o);
    if (a[v] == 49) return;
    a[v] = '1';
    f(v + 1, o - 1);
    a[v] = '0';
}

int main() {
    int k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        char s[16];
        scanf("%s", s);
        for (int j = 4; s[j + 4]; j++) p[i][j - 4] = s[j];
    }
    f(0, k - 5);
    printf("%d", r);
}
