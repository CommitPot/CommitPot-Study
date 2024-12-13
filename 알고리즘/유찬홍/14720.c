#include <stdio.h>

int main() {
    int n, b = 0, c = 0;
    scanf("%d", &n);
    for (int i = 0, a; i < n; i++) {
        scanf("%d", &a);
        if (a == b) b = (b + 1) % 3, c++;
    }
    printf("%d", c);
}
