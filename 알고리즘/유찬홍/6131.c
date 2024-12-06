#include <stdio.h>

int main() {
    int n, c = 0;
    scanf("%d", &n);
    for (int i = 1; i <= 500; i++) {
        for (int j = i; j <= 500; j++) {
            if (i * i + n == j * j) c++;
        }
    }
    printf("%d", c);
}
