#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    printf("%.0lf", pow(2, (int) log2(n)));
}
