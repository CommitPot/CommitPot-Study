#include <stdio.h>
#include <string.h>

int main() {
    int r = 0;
    char s[5], *v[8] = {"0132", "0231", "1320", "1023", "3201", "3102", "2013", "2310"};
    scanf("%s%s", s, &s[2]);
    for (int i = 0; i < 8; i++) {
        char p[5];
        for (int j = 0; j < 4; j++) {
            p[j] = s[v[i][j] - 48];
        }
        p[4] = 0;
        if (!strcmp(p, "HEPC")) r = 1;
    }
    printf("%s", r ? "YES" : "NO");
}
