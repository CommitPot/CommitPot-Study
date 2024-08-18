#include <stdio.h>

int main() {
    int n;
    char s[101];
    scanf("%d %s", &n, s);
    for (int i = 0; i < n; i++) {
        s[i] = s[i] == '?' ? s[n - i - 1] == '?' ? 'a' : s[n - i - 1] : s[i];
    }
    printf("%s", s);
}
