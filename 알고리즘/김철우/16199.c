#include<stdio.h>

int main() {
    int y1, m1, d1, y2, m2, d2, year1, year2, year3;
    scanf("%d %d %d", &y1, &m1, &d1);
    scanf("%d %d %d", &y2, &m2, &d2);
    
    if (m1 < m2)
        year1 = y2 - y1;
    else if (m1 == m2 && d1 <= d2)
        year1 = y2 - y1;
    else
        year1 = y2 - y1 - 1;
    
    year2 = y2 - y1 + 1;

    year3 = y2 - y1;

    printf("%d\n%d\n%d", year1, year2, year3);
    return 0;
}
