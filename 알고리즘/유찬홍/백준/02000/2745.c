#include <stdio.h>
#include <string.h>

int main() {
    int n, r = 0;
    char s[32];
    scanf("%s %d", s, &n);
    int l = strlen(s);
    for (int i = l - 1, j = 1; i >= 0; i--, j *= n) {
        int x = s[i];
        r += (x < 59 ? x - 48 : x - 55) * j;
    }
    printf("%d", r);
}
