#include <stdio.h>
#include <string.h>

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        int r, r1;
        char rs[21], rs1[21];
        scanf("%d %s %d", &n, rs, &r);
        for (int i = 1; i < n; i++) {
            scanf("%s %d", rs1, &r1);
            if (r1 > r) r = r1, strcpy(rs, rs1);
        }
        printf("%s\n", rs);
    }
}
