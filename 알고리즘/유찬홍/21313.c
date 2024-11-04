#include <stdio.h>

int main() {
    int n;
    char s[2002];
    scanf("%d", &n);
    for (int i = 0; i < n * 2 - 2; i++) s[i] = i & 1 ? 32 : (i / 2) & 1 ? 50 : 49;
    s[n * 2 - 2] = n & 1 ? 51 : 50, s[n * 2 - 1] = 0;
    printf("%s", s);
}
