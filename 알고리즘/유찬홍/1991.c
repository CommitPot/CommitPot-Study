#include <stdio.h>

int arr[26][2];

void wjsdnl(int n) {
    if (n == -1) return;
    printf("%c", n + 65);
    wjsdnl(arr[n][0]);
    wjsdnl(arr[n][1]);
}

void wnddnl(int n) {
    if (n == -1) return;
    wnddnl(arr[n][0]);
    printf("%c", n + 65);
    wnddnl(arr[n][1]);
}

void gndnl(int n) {
    if (n == -1) return;
    gndnl(arr[n][0]);
    gndnl(arr[n][1]);
    printf("%c", n + 65);
}

int main() {
    int n;
    char a, b, c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c %c %c", &a, &b, &c);
        int m = a - 65;
        if (b == '.') arr[m][0] = -1;
        else arr[m][0] = b - 65;
        if (c == '.') arr[m][1] = -1;
        else arr[m][1] = c - 65;
    }
    wjsdnl(0);
    printf("\n");
    wnddnl(0);
    printf("\n");
    gndnl(0);
}