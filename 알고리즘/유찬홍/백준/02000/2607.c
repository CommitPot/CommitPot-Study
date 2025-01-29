#include <stdio.h>

int main() {
    int n, a[26] = {}, r = 0;
    char s[11];
    scanf("%d %s", &n, s);
    for (int i = 0; s[i]; i++) a[s[i] - 65]++;
    while (--n) {
        scanf("%s", s);
        int b[26] = {}, c = 0, d = 0;
        for (int i = 0; s[i]; i++) b[s[i] - 65]++;
        for (int i = 0; i < 26; i++) {
            if (a[i] > b[i]) c += a[i] - b[i];
            if (a[i] < b[i]) d += b[i] - a[i];
        }
        if (c + d < 2 || (c < 2 && d < 2)) r++;
    }
    printf("%d", r);
}
