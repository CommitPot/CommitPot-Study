#include <stdio.h>

int main() {
    int a[10], r = 0;
    for (int i = 0; i < 10; i++) scanf("%d", &a[i]);
    for (int i = 0, j; i < 10; i++) {
        scanf("%d", &j);
        r += (a[i] == j ? 0 : a[i] > j ? 1 : -1);
    }
    printf("%c", r ? r > 0 ? 'A' : 'B' : 'D');
}
