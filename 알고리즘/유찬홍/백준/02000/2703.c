#include <stdio.h>

int main() {
    int n;
    char s[101], a[27];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int b[26] = {};
        scanf(" %[^\n] %s", s, a);
        for (int j = 0; a[j]; j++) b[j] = a[j];
        for (int j = 0; s[j]; j++) {
            if (s[j] != 32) s[j] = b[s[j] - 65];
        }
        printf("%s\n", s);
    }
}
