#include <stdio.h>
#include <string.h>

int main() {
    int n, r = 0;
    char v[11];
    scanf("%d", &n);
    for (int i = 0, j; i < n; i++) {
        char s[11];
        scanf("%s %d", s, &j);
        if (j > r || (j == r && strcmp(v, s) > 0)) strcpy(v, s), r = j;
    }
    printf("%s", v);
}
