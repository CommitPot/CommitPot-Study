#include <stdio.h>

int main() {
    int n = 0, n1=0,n2=0;
    scanf("%d", &n);

    n1 = n * 0.78;
    n2 = n - (n * 0.2 * 0.22);
    printf("%d %d", n1, n2);
}
