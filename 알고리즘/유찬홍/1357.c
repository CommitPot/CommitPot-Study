#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char x[5], x1[5], y[5], y1[5];
    scanf("%s %s", x, y);
    int a = 0;
    int xLen = strlen(x);
    int yLen = strlen(y);
    for (int i = xLen - 1; i >= 0; i--) {
        x1[a++] = x[i];
    }
    a = 0;
    for (int i = yLen - 1; i >= 0; i--) {
        y1[a++] = y[i];
    }
    a = 0;
    int x2 = atoi(x1);
    int y2 = atoi(y1);
    int sum = x2 + y2;
    while (sum > 0) {
        int w = sum % 10;
        if (w != 0 && !a) a++;
        if (a) printf("%d", w);
        sum /= 10;
    }
}
