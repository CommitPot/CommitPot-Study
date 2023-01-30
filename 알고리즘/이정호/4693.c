#include <stdio.h>

int d(int number) {
    int sum = number;

    while (number != 0) {
        sum += (number % 10); // 자리수 찾기 위함 -> 자리수(number)
        number = number / 10;
    }
    return sum;
}

int main() {

    int arr[10001] = {0,};

    for (int i = 1; i < 10001; i++) {
        int n = d(i);
        if (n < 10001) {
            arr[n] = 1;
        }
    }

    for (int j = 1; j < 10001; j++) {
        if (arr[j] != 1) {
            printf("%d\n", j);
        }
    }
}
