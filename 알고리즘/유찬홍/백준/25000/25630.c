#include <stdio.h>

int main() {
    int n, r = 0;
    char s[101];
    scanf("%d %s", &n, s);
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) r++;
    }
    printf("%d", r);
}
