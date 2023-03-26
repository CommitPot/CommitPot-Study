#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = n; i >= 0; i--) {
        int a = i, s, c = 0, d = 0;
        while (a > 0) {
            s = a % 10;
            a /= 10;
            c++;
            if (s == 4 || s == 7) d++;
        }
        if (c == d) {
            printf("%d", i);
            return 0;
        }
    }
}