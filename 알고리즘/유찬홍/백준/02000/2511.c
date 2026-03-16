#include <stdio.h>

int main() {
    int a[20], b[3] = {0, 0, -1};
    for (int i = 0; i < 20; i++) scanf("%d", &a[i]);
    for (int i = 0; i < 10; i++) {
        if (a[i] == a[i + 10]) b[0]++, b[1]++;
        else b[a[i] > a[i + 10] ? 0 : 1] += 3, b[2] = a[i] > a[i + 10] ? 0 : 1;
    }
    printf("%d %d\n%c", b[0], b[1], b[0] < b[1] ? 'B' : b[0] > b[1] ? 'A' : b[2] < 0 ? 'D' : b[2] ? 'B' : 'A');
}
