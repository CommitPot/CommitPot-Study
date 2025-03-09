#include <stdio.h>

int main() {
    int a, b, c, d, e = 0;
    char s[201];
    scanf("%d %d", &a, &b);
    c = d = a * b;
    while (c || d) {
        if (c > d) s[e++] = 49, c -= b;
        else if (c < d) s[e++] = 50, d -= a;
        else c -= b, d -= a, s[e++] = 51;
    }
    for (int i = 1; i <= e; i++) printf("%c", s[e - i]);
}
