#include <stdio.h>

int main() {

    int T = 0, N = 0;
    int arr[10000] = {0, 1, 2, 4};

    for (int i = 4; i < 12; i++) {
        arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
    }

    scanf("%d", &T);

    for (int j = 0; j < T; j++) {
        scanf("%d", &N);
        printf("%d\n", arr[N]);
    }
}
