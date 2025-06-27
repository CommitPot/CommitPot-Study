#include <stdio.h>
#include <string.h>

int main() {
    char s[51];
    scanf("%s", s);
    int l = strlen(s), i;
    for (i = 0; s[i]; i++) {
        int p = 0;
        for (int j = i, k = l - 1; j < k; j++, k--) {
            if (s[j] != s[k]) p = 1;
        }
        if (!p) break;
    }
    printf("%d", l + i);
}
