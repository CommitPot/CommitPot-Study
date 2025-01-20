#include <stdio.h>

int main() {
    int n, a[4] = {}, b;
    char c[11];
    scanf("%d", &n);
    while (n--) {
        scanf("%s %d", c, &b);
        if (*c == 'B') a[0] += b;
        else if (*c == 'S') a[1] += b;
        else if (*c == 'L') a[2] += b;
        else a[3] += b;
    }
    printf("%s", a[0] == 5 | a[1] == 5 | a[2] == 5 | a[3] == 5 ? "YES" : "NO");
}
