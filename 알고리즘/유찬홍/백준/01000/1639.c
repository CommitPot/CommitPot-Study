#include <stdio.h>

int main() {
    int r = 0;
    char s[51];
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        int l = 0;
        for (int j = i, k = i + 1, m = 0, n = 0; j > -1 && s[k]; j--, k++) {
            m += s[j];
            n += s[k];
            if (m == n) l = k - j + 1;
        }
        r = r > l ? r : l;
    }
    printf("%d", r);
}
