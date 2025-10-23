#include <stdio.h>

int main() {
    int r = 0;
    char s[1000001];
    scanf("%*d %s", s);
    for (int i = 0; s[i]; i++) r += s[i] - 48;
    printf("%d", r);
}
