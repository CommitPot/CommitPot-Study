#include <stdio.h>

int main() {
    int n, c[2] = {}, a, b;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &a, &b);
        if (a > b) c[0]++;
        else if (a < b) c[1]++;
        else continue;
    }
    printf("%d %d", c[0], c[1]);
}
