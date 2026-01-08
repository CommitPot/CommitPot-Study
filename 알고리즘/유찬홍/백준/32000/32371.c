#include <stdio.h>

int main() {
    int a[128][128] = {}, b[128][2] = {};
    char s[11];
    for (int i = 0; i < 4; i++) {
        scanf("%s", s);
        for (int j = 0; s[j]; j++) {
            b[s[j]][0] = i;
            b[s[j]][1] = j;
        }
    }
    scanf("%s", s);
    for (int i = 0; s[i]; i++) a[b[s[i]][0]][b[s[i]][1]] = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 10; j++) {
            if (a[i][j] && a[i][j + 1] && a[i + 1][j]) {
                for (int k = 33; k < 128; k++) {
                    if (b[k][0] == i + 1 && b[k][1] == j + 1) {
                        printf("%c", k);
                        return 0;
                    }
                }
            }
        }
    }
}
