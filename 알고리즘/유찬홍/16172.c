#include <stdio.h>
#include <string.h>

int main() {
    char s[200001], k[200001];
    scanf("%s %s", s, k);
    for (int i = 0, j = 0; s[i]; i++) {
        if (s[i] > 58) s[j++] = s[i];
        if (!s[i]) s[j] = 0;
    }
    printf("%d", !!strstr(s, k));
}
