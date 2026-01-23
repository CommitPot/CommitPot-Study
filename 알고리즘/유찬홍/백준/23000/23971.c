#include <stdio.h>

int main() {
    int a[4], n = 0, m = 0;
    for (int i = 0; i < 4; i++) scanf("%d", &a[i]);
    for (int i = 0; i < a[0]; i += a[2] + 1) n++;
    for (int i = 0; i < a[1]; i += a[3] + 1) m++;
    printf("%d", n * m);
}
