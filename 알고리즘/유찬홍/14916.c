#include <stdio.h>

int main() {
    int n, count = 0;
    scanf("%d", &n);
    while (n > 0) {
        count++;
        if ((n - 5) % 5 == 0) n -= 5;
        else {
            if (n - 2 >= 0) n -= 2;
            else {
                printf("-1");
                return 0;
            }
        }
    }
    printf("%d", count);
    return 0;
}