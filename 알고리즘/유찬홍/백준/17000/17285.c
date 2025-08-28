#include <stdio.h>

int main() {
    char s[101];
    scanf("%s", s);
    int k = s[0] ^ 67;
    for (int i = 0; s[i]; i++) s[i] ^= k;
    printf("%s", s);
}
