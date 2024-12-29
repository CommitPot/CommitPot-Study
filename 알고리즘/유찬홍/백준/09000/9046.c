#include <stdio.h>

int main() {
    int n;
    char s[256];
    scanf("%d", &n);
    while (n--) {
        int a[27] = {}, b = 0, c = 0;
        scanf(" %[^\n]", s);
        for (int i = 0; s[i]; i++) {
            if (s[i] != 32) a[s[i] - 96]++;
        }
        for (int i = 1; i < 27; i++) {
            if (b == a[i]) c = 0;
            if (b < a[i]) b = a[i], c = i;
        }
        printf("%c\n", c ? c + 96 : '?');
    }
}
