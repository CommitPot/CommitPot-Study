#include <stdio.h>

int f(int x) { return x * x * x; }

int main() {
    for (int i = 2; i <= 100; i++) {
        for (int j = 2; j <= 100; j++) {
            for (int k = j + 1; k <= 100; k++) {
                for (int l = k + 1; l <= 100; l++) {
                    if (f(j) + f(k) + f(l) == f(i)) {
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", i, j, k, l);
                    }
                }
            }
        }
    }
}
