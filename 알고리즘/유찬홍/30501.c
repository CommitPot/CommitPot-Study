#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char a[101];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", a);
        if (strchr(a, 'S')) {
            printf("%s", a);
            break;
        }
    }
}
