#include <stdio.h>

int main() {
    int t = 0, tn = 0;
    int arr[101] = {0};

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d", &tn);
        int sum = 0;
        for (int j = 0; j < tn; j++) {
            scanf("%d", &arr[j]);
            sum += arr[j];
        }
        printf("%d", sum);
        printf("\n");
    }
}
