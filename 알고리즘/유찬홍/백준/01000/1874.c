#include <stdio.h>

int main() {
    int n, top = -1, c = 0, co = 0, stack[100001], arr[100001], arr1[200001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        while (arr[i] > c) {
            stack[++top] = ++c;
            arr1[co++] = 1;
        }
        if (stack[top] != arr[i]) {
            printf("NO");
            return 0;
        } else {
            top--;
            arr1[co++] = 0;
        }
    }
    for (int i = 0; i < co; i++) {
        printf("%c\n", arr1[i] ? '+' : '-');
    }
    return 0;
}