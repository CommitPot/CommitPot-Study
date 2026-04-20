#include <stdio.h>

int main() {
    int n, c = 1;
    char s[100001];
    scanf("%d %s", &n, s);
    for (int i = 0; s[i]; i++) c += s[i] != 67;
    printf("%d", n / c);
}
