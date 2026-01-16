#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char s[201], r[201];
    scanf("%d %s", &n, s);
    int l = strlen(s);
    r[l] = 0;
    for (int i = 0, p = 0; i < n; i++) {
        for (int j = 0, k = 0; j < l; j += n, k++) {
            r[p++] = s[j + (k & 1 ? n - i - 1 : i)];
        }
    }
    printf("%s", r);
}
