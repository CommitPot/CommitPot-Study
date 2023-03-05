#include <stdio.h>

typedef long long int llint;
int c = 0;

void dfs(llint a, llint b, int cnt) {
    if (a > b) {
        return;
    }
    if (a == b) {
        c = cnt;
        return;
    } else {
        dfs(a * 2, b, cnt + 1);
        dfs(a * 10 + 1, b, cnt + 1);
    }
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    dfs(a, b, 1);
    printf("%d", !c ? -1 : c);
    return 0;
}