#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("y%c", a + b == 4 || (a == 2 && b == 1) ? 'j' : 't');
}
