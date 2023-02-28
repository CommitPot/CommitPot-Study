#include <stdio.h>

int main() {
    int n = 0, m = 0, i = 0, j = 0, k = 0;
    int arr[101] = {0};

    scanf("%d %d", &n, &m);

    for(int p=0; p<m; p++) {
        scanf("%d %d %d", &i, &j, &k);

        for(int q=i; q<=j; q++) {
            arr[q] = k;
        }
    }

    for(int m=1; m<=n; m++) {
        printf("%d ", arr[m]);
    }
}
