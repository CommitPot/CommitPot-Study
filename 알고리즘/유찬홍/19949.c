#include <stdio.h>

int arr[11], rs = 0;

void bt(int len, int *arr1) {
    if (len > 2 && arr1[len - 1] == arr1[len - 2] && arr1[len - 1] == arr1[len - 3]) return;
    if (len == 10) {
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            if (arr[i] == arr1[i]) sum++;
        }
        if (sum >= 5) rs++;
        return;
    }
    for (int i = 1; i < 6; i++) {
        arr1[len++] = i;
        bt(len--, arr1);
    }
}

int main() {
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    int arr1[11];
    bt(0, arr1);
    printf("%d", rs);
}
