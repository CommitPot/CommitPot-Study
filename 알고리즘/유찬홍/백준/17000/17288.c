#include <stdio.h>
#include <string.h>

int main() {
    char s[101];
    scanf("%s", s);
    int r = 0, l = strlen(s);
    for (int i = 2; i < l; i++) {
        if (s[i - 2] + 1 == s[i - 1] && s[i - 1] + 1 == s[i]) {
            int k = i;
            while (i < l && s[i] + 1 == s[i + 1]) i++;
            if (k == i) r++, i += 2;
        }
    }
    printf("%d", r);
}
