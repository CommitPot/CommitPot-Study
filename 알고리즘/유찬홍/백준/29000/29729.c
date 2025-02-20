#include <stdio.h>

int main() {
    int s, l = 0, n, m;
    char a;
    scanf("%d %d %d", &s, &n, &m);
    for (int i = 0; i < n + m; i++) {
        scanf("%c ", &a);
        if (a == 49) l++;
        else l--;
        if (l == s) s *= 2;
    }
    printf("%d", s);
}
