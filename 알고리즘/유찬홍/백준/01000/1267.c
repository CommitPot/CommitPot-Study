#include <stdio.h>

int main() {
    int n, b[2] = {};
    scanf("%d", &n);
    for (int i = 0, a; i < n; i++) {
        scanf("%d", &a);
        b[0] += a / 30 * 10 + ((a + 1) % 30 ? 10 : 0);
        b[1] += a / 60 * 15 + ((a + 1) % 60 ? 15 : 0);
    }
    printf("%s ", b[0] < b[1] ? "Y" : b[0] > b[1] ? "M" : "Y M");
    printf("%d", b[0] < b[1] ? b[0] : b[1]);
}
