#include <stdio.h>
#include <math.h>

#define MAX_SIZE 10000000

int main() {
    int n, count = 0, arr[MAX_SIZE + 1] = {0}, len = sqrt(MAX_SIZE);
    scanf("%d", &n);
    for (int i = 2; i <= len; i++) {
        if (arr[i] == 0) {
            for (int j = i * 2; j <= MAX_SIZE; j += i) {
                arr[j] = 1;
            }
        }
    }
    for (int i = 2; i <= MAX_SIZE * 2; i++) {
        if (arr[i] == 0) count++;
        if (count == n) {
            printf("%d", i);
            break;
        }
    }
    return 0;
}