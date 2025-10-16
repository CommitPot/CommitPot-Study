#include <stdio.h>

int main() {
    char s[100001];
    scanf("%*d %s", s);
    for (int i = 1, j = 0; s[i]; i++) {
        if (s[i - 1] == s[i] + 1 || s[i - 1] + 1 == s[i]) j++;
        else j = 0;
        if (j > 3) *s = 1;
    }
    printf("%s", *s == 1 ? "YES" : "NO");
}
