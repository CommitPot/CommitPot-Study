#include <stdio.h>

int main() {
    int n, l, r = 1;
    scanf("%d %d", &n, &l);
    while (n) {
        int k = 0, j = r;
        while (j) {
            if (j % 10 == l) k = 1;
            j /= 10;
        }
        if (!k) n--;
        r++;
    }
    printf("%d", r - 1);
}
