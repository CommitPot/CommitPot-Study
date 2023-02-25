#include <stdio.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    if (m <= 2)
        printf("NEWBIE!");
    else if (n < m)
        printf("TLE!");
    else
        printf("OLDBIE!");
    return 0;
}
