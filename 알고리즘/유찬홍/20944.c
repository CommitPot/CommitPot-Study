#include <stdio.h>

int main() {
    int n;
    char s[1000001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) s[i] = 'a';
    s[n] = 0;
    printf("%s", s);
}
