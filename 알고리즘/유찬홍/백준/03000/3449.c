#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        char a[102], b[102];
        int c = 0;
        scanf("%s %s", a, b);
        for (int i = 0; a[i]; i++) {
            if (a[i] != b[i]) c++;
        }
        printf("Hamming distance is %d.\n", c);
    }
}
