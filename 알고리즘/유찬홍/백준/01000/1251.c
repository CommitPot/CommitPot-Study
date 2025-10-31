#include <stdio.h>
#include <string.h>

int main() {
    char s[51], r[51];
    scanf("%s", s);
    memset(r, 122, 51);
    int l = strlen(s);
    for (int i = 0; i < l - 1; i++) {
        for (int j = i + 1; j < l - 1; j++) {
            char t[51];
            int o = 0;
            for (int k = i; k >= 0; k--) t[o++] = s[k];
            for (int k = j; k > i; k--) t[o++] = s[k];
            for (int k = l - 1; k > j; k--) t[o++] = s[k];
            t[l] = 0;
            if (strcmp(r, t) > 0) strcpy(r, t);
        }
    }
    printf("%s", r);
}
