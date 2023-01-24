#include <stdio.h>

#define MAX_SIZE 10000

int main() {
   int arr[MAX_SIZE + 1] = {0,};

   int n = 0, num = 0;

   scanf("%d", &n);

   for (int k = 0; k < n; k++) {
       scanf("%d", &num);
       arr[num]++; // 숫자를 받아서 그 숫자의 index -> 값을 넣는다
   }

   for (int i = 1; i < MAX_SIZE + 1; i++) { // 배열을 모두 순회
       for (int j = 0; j < arr[i]; j++) { // arr[10000]까지 돌면서 1부터 있으면 출력하고 아니면 출력하지 않는 방식으로 정렬
           printf("%d\n", i);
       }
   }
   return 0;
}

백준 수 정렬하기 3
