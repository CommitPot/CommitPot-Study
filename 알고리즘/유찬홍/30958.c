#include <stdio.h>

int main() {
    int n, a[26] = {};
    char s[100001];
    scanf("%d %[^\n]", &n, s);
    for (int i = 0; s[i]; i++) {
        if (s[i] >= 97 && s[i] <= 122) a[s[i] - 97]++;
    }
    n = 0;
    for (int i = 0, j = 0; i < 26; i++) {
        if (n < a[i]) n = a[i];
    }
    printf("%d", n);
}
