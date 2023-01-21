#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int isFrime(int n) {
    int len = sqrt(n);
    for (int i = 2; i <= len; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int a, b, arr[10000001] = {0};
    scanf("%d %d", &a, &b);
    if (b >= 10000000) b = 10000000;
    for (int i = a; i <= b; i++) {
        char arr1[10];
        int l = 0, nTmp = i, d = i, count = 0;
        while (nTmp != 0) {
            nTmp /= 10;
            l++;
        }
        while (l >= 0) {
            arr1[--l] = d % 10 + '0';
            d /= 10;
        }
        int len = strlen(arr1);
        for (int j = 0, k = len - 1; j < len / 2; j++, k--) {
            if (arr1[j] == arr1[k]) count++;
        }
        if (count == len / 2) arr[i] = atoi(arr1);
    }
    for (int i = a; i <= b; i++) {
        if (arr[i]) {
            if (isFrime(i)) printf("%d\n", arr[i]);
        }
    }
    printf("-1");
}