#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        printf("%d is %s\n", a, abs(a) % 2 ? "odd" : "even");
    }
}
