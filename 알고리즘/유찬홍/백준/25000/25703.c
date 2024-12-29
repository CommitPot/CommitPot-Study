#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    printf("int a;\nint *ptr = &a;\n");
    for (int i = 2; i <= n; i++) {
        printf("int ");
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        if (i == 2) printf("ptr%d = &ptr;\n", i);
        else printf("ptr%d = &ptr%d;\n", i, i - 1);
    }
}
