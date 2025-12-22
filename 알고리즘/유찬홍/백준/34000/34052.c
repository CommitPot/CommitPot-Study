#include <stdio.h>

int main() {
    int r = 0;
    for (int i = 0, a; i < 4; i++) {
        scanf("%d", &a);
        r += a;
    }
    printf("%s", r <= 1500 ? "Yes" : "No");
}
