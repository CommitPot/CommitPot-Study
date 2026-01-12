#include <stdio.h>

int main() {
    int a, t, n, b[2] = {};
    scanf("%d %d %d", &a, &t, &n);
    for (int i = 2, c = 0; ; i++) {
        for (int j = 0; j < 4; j++, c++) {
            b[!(!j || j == 2)]++;
            if (b[n] == t) {
                printf("%d\n", c % a);
                return 0;
            }
        }
        for (int j = 0; j < i; j++, c++) {
            b[0]++;
            if (b[n] == t) {
                printf("%d\n", c % a);
                return 0;
            }
        }
        for (int j = 0; j < i; j++, c++) {
            b[1]++;
            if (b[n] == t) {
                printf("%d\n", c % a);
                return 0;
            }
        }
    }
}
