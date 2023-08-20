#include <stdio.h>

int main() {
    int n, a, b, c = 0;
    scanf("%d %d", &n, &a);
    for (int i = 1; i < n; i++) {
        scanf("%d", &b);
        if (a <= b) c++;
        a = b;
    }
    printf("%d", !c ? 1 : c + 1);
}
