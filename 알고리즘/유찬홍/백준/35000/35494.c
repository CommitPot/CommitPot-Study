#include <stdio.h>

int main() {
    int n, a = 0, b;
    long long r = 0;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &b);
        if (a < b) a = b;
        r += a;
    }
    printf("%s!", r % 3 ? "Oh My God" : "Delicious");
}
