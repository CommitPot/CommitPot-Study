#include <stdio.h>

int Euclidean(int a, int b)
{
    int r = a % b;
    if (r == 0) {
        return b;
    }
    return Euclidean(b, r);
}


int main() {
    int n, arr[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i < n; i++) {
        int a = Euclidean(arr[0], arr[i]);
        printf("%d/%d\n", arr[0] / a, arr[i]/ a);
    }
    return 0;
}