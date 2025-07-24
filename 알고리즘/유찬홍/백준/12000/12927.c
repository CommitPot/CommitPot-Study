#include <stdio.h>
#include <string.h>

int main() {
    int r = 0;
    char s[1001];
    scanf("%s", s);
    int l = strlen(s);
    for (int i = 0; i < l; i++) {
        if (s[i] == 'N') continue;
        r++;
        for (int j = i; j < l; j += i + 1) s[j] = s[j] == 'N' ? 'Y' : 'N';
    }
    printf("%d", r);
}
