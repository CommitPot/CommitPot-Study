#include <stdio.h>

int main() {
    int n, m;
    scanf("%d", &n);
    while (n--){
        scanf("%d", &m);
        printf("%d ", m > 299 ? 1 : m > 274 ? 2 : m > 249 ? 3 : 4);
    }
}
