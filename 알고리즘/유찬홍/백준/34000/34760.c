#include <stdio.h>

int main() {
    int r = 0;
    for (int i = 0, a; i < 15; i++) {
        scanf("%d", &a);
        if (a >= r) r = a + (i != 14);
    }
    printf("%d", r);
}
