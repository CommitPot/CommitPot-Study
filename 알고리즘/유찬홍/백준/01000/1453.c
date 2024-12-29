#include <stdio.h>

int main() {
    int n, a, c = 0, arr[101] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        !arr[a] ? arr[a]++ : c++;
    }
    printf("%d", c);
}
