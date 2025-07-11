#include <stdio.h>

int main() {
    int n, x = 1000, y = 1000, r = 1, a[2002][2002] = {};
    char s[1001];
    scanf("%d %s", &n, s);
    a[x][y] = 1;
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'E') y++;
        else if (s[i] == 'W') y--;
        else if (s[i] == 'S') x++;
        else x--;
        if (!a[x][y]) r++;
        a[x][y] = 1;
    }
    printf("%d", r);
}
