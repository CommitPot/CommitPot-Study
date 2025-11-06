#include <stdio.h>

int main() {
    int r = 1;
    char s[100001];
    scanf("%s", s);
    for (int i = 1, j = 1; s[i]; i++) {
        if (s[i - 1] < s[i]) r += ++j;
        else r++, j = 1;
    }
    printf("%d", r);
}
