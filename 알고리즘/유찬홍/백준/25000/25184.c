#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) printf("%d ", n & 1 ? i & 1 ? n / 2 + 1 + i - i / 2 : i / 2 + 1 : (i & 1 ? n : n / 2) - i / 2);
}
