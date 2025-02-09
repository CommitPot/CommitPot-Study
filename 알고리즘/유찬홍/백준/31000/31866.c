#include <stdio.h>

int f(int v) {
    return v == 1 || v == 3 || v == 4;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    if ((f(a) && f(b)) || a == b) {
        printf("=");
    } else if ((!f(a) && f(b)) || (!a && b == 2) || (a == 2 && b == 5) ||
               (a == 5 && !b)) {
        printf(">");
    } else printf("<");
}
