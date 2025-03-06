#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n + 2; i++) {
        printf("@");
        for (int j = 0; j < n; j++) printf("%c", !i || i == n + 1 ? '@' : ' ');
        printf("@\n");
    }
}
