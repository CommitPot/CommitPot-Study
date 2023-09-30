#include <stdio.h>

int cnt = 0;

void func(int len, int n, int sum) {
    if (len == n) {
        if (sum % 3 == 0) cnt++;
        return;
    }
    if (len > 0) {
        sum *= 10;
        func(len + 1, n, sum);
        sum /= 10;
    }
    sum = sum * 10 + 1;
    func(len + 1, n, sum);
    sum /= 10;
    sum = sum * 10 + 2;
    func(len + 1, n, sum);
}

int main() {
    int n;
    scanf("%d", &n);
    func(0, n, 0);
    printf("%d", cnt);
}
