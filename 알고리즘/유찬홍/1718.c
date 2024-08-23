#include <stdio.h>

int main() {
    char s[30001], k[30001];
    scanf("%[^\n] %s", s, k);
    for (int i = 0, j = 0; s[i]; i++, j++) {
        if (!k[j]) j = 0;
        if (s[i] == ' ') continue;
        s[i] = s[i] <= k[j] ? 122 - k[j] + s[i] : s[i] - k[j] + 96;
    }
    printf("%s", s);
}
