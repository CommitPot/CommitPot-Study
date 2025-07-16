#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) { return a < b ? a : b; }

int main() {
    int r = 0;
    char s[101], a = 65;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        r += min(abs(s[i] - a), -abs(a - s[i]) + 26);
        a = s[i];
    }
    printf("%d", r);
}
