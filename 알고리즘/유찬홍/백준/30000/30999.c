#include <stdio.h>

int main() {
    int n, m, r = 0;
    char s[100];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        int x = 0, y = 0;
        for (int j = 0; j < m; j++) {
            if (s[j] == 'O') x++;
            else y++;
        }
        if (x > y) r++;
    }
    printf("%d", r);
}
