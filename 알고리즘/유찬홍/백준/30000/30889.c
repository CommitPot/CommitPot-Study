#include <stdio.h>

int main() {
    int n, l;
    char c, s[10][21];
    scanf("%d", &n);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            s[i][j] = '.';
        }
        s[i][20] = 0;
    }
    while (n--) {
        scanf(" %c%d", &c, &l);
        s[c - 65][l - 1] = 'o';
    }
    for (int i = 0; i < 10; i++) {
        printf("%s\n", s[i]);
    }
}
