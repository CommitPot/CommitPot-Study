#include <stdio.h>

int main() {
    char s[101];
    int n, a, b;
    scanf("%s %d", s, &n);
    while (n--) {
        scanf("%d %d", &a, &b);
        char t = s[a];
        s[a] = s[b];
        s[b] = t;
    }
    printf("%s", s);
}
