#include <stdio.h>
#include <stdlib.h>

typedef struct md {
    int countryNum, num, grade;
} md;

int comp(const void *a, const void *b) {
    return (((md *) b)->grade - ((md *) a)->grade);
}

int main() {
    int n, count[100];
    md arr[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &arr[i].countryNum, &arr[i].num, &arr[i].grade);
    }
    qsort(arr, n, sizeof(arr[0]), comp);
    for (int i = 1; i < n; i++) {
        if (arr[i].countryNum == arr[i - 1].countryNum) count[arr[i].countryNum]++;
        if (count[arr[i].countryNum] > 1) {
            arr[i].countryNum = 0;
            arr[i].grade = 0;
            arr[i].num = 0;
        }
    }
    qsort(arr, n, sizeof(arr[0]), comp);
    for (int i = 0; i < 2; i++) {
        printf("%d %d\n", arr[i].countryNum, arr[i].num);
    }
    printf("%d %d", arr[2].countryNum, arr[2].num);
}