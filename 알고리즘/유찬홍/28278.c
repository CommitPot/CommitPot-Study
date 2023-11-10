#include <stdio.h>

int main() {
    int n, a, b, stack[1000001], top = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        switch (a) {
            case 1:
                scanf("%d", &b);
                stack[++top] = b;
                break;
            case 2:
                printf("%d\n", top == -1 ? -1 : stack[top--]);
                break;
            case 3:
                printf("%d\n", top + 1);
                break;
            case 4:
                printf("%d\n", top == -1 ? 1 : 0);
                break;
            case 5:
                printf("%d\n", top == -1 ? -1 : stack[top]);
                break;
        }
    }
}
