#include <stdio.h>

int main() {
    int n, a, b, c = 0, r = 1;
    scanf("%d %d", &n, &a);
    while(--n) {
        scanf("%d", &b);
        if (a == b) r = 0;
        if (a > b && !c) c = 1;
        else if (a < b && c) r = 0;
        a = b;
    }
    printf("%s", r ? "YES" : "NO");
}
