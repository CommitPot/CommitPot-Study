#include <stdio.h>

int main() {
    int a, b, c, d, e = 0, arr[101][101] = {0};
    for (int i = 0; i < 4; i++) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        for (int j = a; j < c; j++) {
            for (int k = b; k < d; k++) {
                if (!arr[j][k]) e++;
                arr[j][k] = 1;
            }
        }
    }
    printf("%d", e);
}
