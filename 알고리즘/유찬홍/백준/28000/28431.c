#include <stdio.h>

int main() {
    int arr[10] = {0}, a;
    for (int i = 0; i < 5; i++) {
        scanf("%d", &a);
        if (!arr[a]) arr[a]++;
        else arr[a]--;
    }
    for (int i = 0; i < 10; i++) {
        if (arr[i]) {
            printf("%d", i);
            break;
        }
    }
}
