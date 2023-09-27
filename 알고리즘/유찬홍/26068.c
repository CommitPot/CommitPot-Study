#include <stdio.h>

int main() {
    int n, d, rs = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" D-%d", &d);
        if (d < 91) rs++;
    }
    printf("%d", rs);
}
