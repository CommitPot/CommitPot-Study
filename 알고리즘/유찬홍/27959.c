#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%s", n * 100 >= m ? "Yes" : "No");
}
