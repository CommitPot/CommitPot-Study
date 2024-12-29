#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, arr[1000001] = {0, 1};
    scanf("%d", &n);
    for (int i = 2; i <= abs(n); i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000000;
    }
    printf("%d\n%d", n <= 0 ? n != 0 ? abs(n) % 2 == 0 ? -1 : 1 : 0 : 1, arr[abs(n)]);
    return 0;
}