#include <stdio.h>

int main() {
    int n, a, i, b[51] = {};
    scanf("%d", &n);
    while (n--) scanf("%d", &a), b[a]++;
    for (i = 0, a = -1; i < 51; i++) {
        if (b[i] == i) a = i > a ? i : a;
    }
    printf("%d", a);
}
