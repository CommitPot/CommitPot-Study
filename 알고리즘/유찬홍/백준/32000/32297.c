#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char s[11];
    scanf("%d %s", &n, s);
    printf("%s", strstr(s, "gori") ? "YES" : "NO");
}
