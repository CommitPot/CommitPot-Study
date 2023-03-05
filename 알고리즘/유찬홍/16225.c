#include <stdio.h>
#include <stdlib.h>

int heap[200001];
int idx = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void push_heap(int newValue) {
    heap[idx++] = newValue;

    int i = idx - 1;

    while (i > 0 && heap[i] > heap[(i - 1) / 2]) {
        swap(heap + i, heap + ((i - 1) / 2));
        i = (i - 1) / 2;
    }
}


void pop_heap() {
    if (idx == 0) return;

    heap[0] = heap[--idx];

    int here = 0;
    while (1) {
        int left = here * 2 + 1, right = here * 2 + 2;

        if (left >= idx) break;

        int next = here;
        if (heap[next] < heap[left]) next = left;
        if (right < idx && heap[next] < heap[right]) next = right;
        if (next == here) break;
        swap(heap + here, heap + next);
        here = next;
    }
}


typedef struct element {
    int a, b;
} element;

int comp(const void *a, const void *b) {
    element a1 = *(element *) a;
    element b1 = *(element *) b;
    if (a1.b > b1.b) return 1;
    else if (a1.b < b1.b) return -1;
    else return 0;
}

int main() {
    int n;
    element arr[200001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].a);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].b);
    }
    qsort(arr, n, sizeof(arr[0]), comp);
    long long int sum = arr[0].a;
    for (int i = 2; i < n - 1; i += 2) {
        push_heap(arr[i].a);
        push_heap(arr[i - 1].a);
        int m = heap[0];
        sum += m;
        pop_heap();
    }
    printf("%lld", sum);
}