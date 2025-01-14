#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0, a; i < n; i++) {
        scanf("%d", &a);
        printf("%s\n", a * a % (a < 10 ? 10 : a < 100 ? 100 : 1000) == a ? "YES" : "NO");
    }
}
