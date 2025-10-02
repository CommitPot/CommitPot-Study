#include <stdio.h>

int main() {
    int a[26], b[26] = {}, k = 0;
    char s[21], r[201];
    scanf("%s %s", s, r);
    for (int i = 0; s[i]; i++) {
        if (!b[s[i] - 65]) a[k++] = s[i], b[s[i] - 65] = 1;
    }
    for (int i = 0; i < 26; i++) if (!b[i]) a[k++] = i + 65;
    for (int i = 0; r[i]; i++) r[i] = a[r[i] - 65];
    printf("%s", r);
}
