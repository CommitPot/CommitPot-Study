#include <stdio.h>
#include <string.h>

int front = 10000, rear = 10000;

int is_empty() {
    if (front == rear) return 1;
    else return 0;
}

void push_front(int *deque, int a) {
    deque[front--] = a;
}

void push_back(int *deque, int a) {
    deque[++rear] = a;
}

int pop_front(int *deque) {
    if (is_empty()) return -1;
    return deque[++front];
}

int pop_back(int *deque) {
    if (is_empty()) return -1;
    return deque[rear--];
}

int main() {
    int n, a, deque[20002];
    char arr[15];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr);
        if (!strcmp(arr, "push_front")) {
            scanf("%d", &a);
            push_front(deque, a);
        } else if (!strcmp(arr, "push_back")) {
            scanf("%d", &a);
            push_back(deque, a);
        } else if (!strcmp(arr, "pop_front")) printf("%d\n", pop_front(deque));
        else if (!strcmp(arr, "pop_back")) printf("%d\n", pop_back(deque));
        else if (!strcmp(arr, "size")) printf("%d\n", rear - front);
        else if (!strcmp(arr, "empty")) printf("%d\n", is_empty());
        else if (!strcmp(arr, "front")) printf("%d\n", is_empty() ? -1 : deque[front + 1]);
        else if (!strcmp(arr, "back")) printf("%d\n", is_empty() ? -1 : deque[rear]);
    }
    return 0;
}