#include <stdio.h>

int main() {
    int n, a, b = 0, c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c);
        if (!i) a = c;
        else {
            if (c < a) a = c;
            if (c - a > b) b = c - a;
        }
        printf("%d ", b);
    }
}
