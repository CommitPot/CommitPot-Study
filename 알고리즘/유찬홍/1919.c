#include <stdio.h>
#include <stdlib.h>

int main() {
    int r = 0, a[26] = {}, b[26] = {};
    char s[1001], s1[1001];
    scanf("%s %s", s, s1);
    for (int i = 0; s[i] != 0; i++) a[s[i] - 97]++;
    for (int i = 0; s1[i] != 0; i++) b[s1[i] - 97]++;
    for (int i = 0; i < 26; i++) {
        r += abs(a[i] - b[i]);
    }
    printf("%d", r);
}
