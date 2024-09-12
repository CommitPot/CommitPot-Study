#include <stdio.h>

int main() {
    int a[5], c = 1;
    for (int i = 0; i < 5; i++) scanf("%d", &a[i]);
    while (1) {
        int b = 0;
        for (int i = 0; i < 5; i++) b += !(c % a[i]);
        if (b > 2) break;
        c++;
    }
    printf("%d", c);
}
