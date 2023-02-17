#include <stdio.h>

int Euclidean(int a, int b) {
    int r = a % b;
    if (r == 0) {
        return b;
    }
    return Euclidean(b, r);
}

int main() {
    int a, b, c, d, e;
    scanf("%d:%d", &a, &b);
    c = Euclidean(a, b);
    printf("%d:%d", a / c, b / c);
}