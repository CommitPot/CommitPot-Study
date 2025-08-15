#include <stdio.h>
#include <string.h>

int main() {
    int a[2] = {}, b[2] = {};
    char s[501];
    scanf("%s", s);
    int l = strlen(s);
    for (int i = 0; s[i]; i++) a[s[i] - 48]++;
    for (int i = 0; s[i]; i++) {
        if (s[i] == 49 && a[1] / 2 > b[1]) s[i] = 50, b[1]++;
    }
    for (int i = l - 1; i >= 0; i--) {
        if (s[i] == 48 && a[0] / 2 > b[0]) s[i] = 50, b[0]++;
    }
    for (int i = 0; s[i]; i++) {
        if (s[i] == 50) continue;
        printf("%c", s[i]);
    }
}
