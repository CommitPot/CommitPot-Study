#include <stdio.h>

int main() {
    int n, k;
    while (scanf("%d %d", &n, &k) != EOF) {
        int count = n, chichen = k;
        chichen += n;
        while (chichen > k) {
            chichen -= k;
            chichen++;
            count++;
        }
        printf("%d\n", count - 1);
    }
    return 0;
}