#include <stdio.h>

int main() {
    int n, a, b[2] = {}, c = 1;
    scanf("%d %d", &n, &a);
    for (int i = 1, d; i < n; i++) {
        scanf("%d", &d);
        if (d >= a) c++;
        else {
            b[0]++;
            if (b[1] < c) b[1] = c;
            c = 1;
        }
        a = d;
    }
    printf("%d %d", ++b[0], b[1] > c ? b[1] : c);
}
