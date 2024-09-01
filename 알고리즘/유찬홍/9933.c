#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char s[100][14];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int l = strlen(s[i]);
            char r[14];
            for (int k = l - 1, m = 0; k >= 0;) r[m++] = s[i][k--];
            if ((i != j && !strcmp(s[i], s[j])) || !strcmp(r, s[j])) {
                printf("%d %c", l, s[i][l / 2]);
                return 0;
            }
        }
    }
}
