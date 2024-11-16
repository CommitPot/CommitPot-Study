#include <stdio.h>

int main() {
    int n, a[1000001] = {}, b = 1, c = 2;
    scanf("%d", &n);
    for (int i = n, j; i > 0; i--) {
        scanf("%d", &j);
        if (j == 1) {
            a[b++] = i;
            while (a[b]) b++;
            c++;
        } else if (j == 2) a[c++] = i;
        else a[n--] = i;
    }
    for (int i = 1; a[i]; i++) printf("%d ", a[i]);
}
