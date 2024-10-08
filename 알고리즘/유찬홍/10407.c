#include <stdio.h>

int main() {
    char a[102];
    scanf("%s", a);
    printf("%d", *a == 49 && !a[1] ? 2 : 1);
}
