#include <stdio.h>

int main() {
    int r = 0, i = 0;
    char s[100001];
    scanf("%s", s);
    while (s[++i]) r += s[i] > s[i - 1];
    printf("%d", i - r);
}
