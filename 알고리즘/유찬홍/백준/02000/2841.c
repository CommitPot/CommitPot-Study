#include <stdio.h>
#include <string.h>

int main() {
    int n, p, s[6][30001], t[6], r = 0;
    memset(t, -1, 24);
    scanf("%d %d", &n, &p);
    for (int i = 0, a, b; i < n; i++) {
        scanf("%d %d", &a, &b);
        while (t[a - 1] > -1 && s[a - 1][t[a - 1]] > b) t[a - 1]--, r++;
        if (t[a - 1] != -1 && s[a - 1][t[a - 1]] == b) continue;
        s[a - 1][++t[a - 1]] = b;
        r++;
    }
    printf("%d", r);
}
