#include <stdio.h>
#include <string.h>

int main() {
    int n, p = 0;
    char s[1001], t[501], d[1001];
    scanf("%d %s", &n, s);
    int l = strlen(s);
    strcpy(d, s);
    do {
        for (int i = 0; i < l / 2; i++) t[l / 2 - i - 1] = s[i * 2 + 1];
        for (int i = 0; i <= l / 2; i++) s[i] = s[i * 2];
        s[l / 2 + 1] = 0;
        strcat(s, t);
        p++;
    } while (strcmp(d, s));
    n %= p;
    while (n--) {
        for (int i = 0; i < l / 2; i++) t[l / 2 - i - 1] = s[i * 2 + 1];
        for (int i = 0; i <= l / 2; i++) s[i] = s[i * 2];
        s[l / 2 + 1] = 0;
        strcat(s, t);
    }
    printf("%s\n", s);
}
