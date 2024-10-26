#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char s[2000001];
    scanf("%d", &n);
    memset(s, 49, n);
    memset(s + n, 48, n - 1);
    printf("%s", s);
}
