#include <stdio.h>
#include <string.h>

int main() {
    char r[5][65], s[16];
    scanf("%s", s);
    int l = strlen(s);
    memset(r, '.', sizeof(r));
    for (int i = 0, j = 2; i < l; i++) {
        r[0][j] = r[1][j - 1] = r[1][j + 1] = r[2][j - 2] =
                                              r[2][j + 2] =
                                              r[3][j + 1] = r[3][j - 1] = r[4][j] = i % 3 == 2 ? '*' : '#';
        if ((i - 1) % 3 == 2) r[2][j - 2] = '*';
        r[2][j] = s[i];
        j += 4;
    }
    for (int i = 0; i < 5; i++) {
        r[i][l * 5 - l + 1] = 0;
        printf("%s\n", r[i]);
    }
}
