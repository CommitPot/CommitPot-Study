#include <stdio.h>

int main() {
    int n;
    char s[] = "SciComLove";
    scanf("%d", &n);
    n %= 10;
    printf("%s", (s + n));
    s[n] = 0;
    printf("%s", s);
}
