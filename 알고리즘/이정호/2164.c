#include <stdio.h>

#define MAX_QUEUE_SIZE 500001

typedef struct queue {
    int data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void init_queue(QueueType *q) {
    q->front = q->rear = 0;
}

int is_empty(QueueType *q) {
    return (q->front == q->rear);
}

int is_full(QueueType *q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(QueueType *q, int data) {
    if (is_full(q)) {
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = data;
}

int dequeue(QueueType *q) {
    if (is_empty(q)) {
        return 0;
    }

    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

int main() {
    QueueType q;

    init_queue(&q);

    int N = 0, j = 0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        enqueue(&q, i + 1);
    }

    while (!is_empty(&q)) {
        j = dequeue(&q); // 처음 빼는 값
        if (is_empty(&q)) { break; }
        j = dequeue(&q);
        enqueue(&q, j);
    }

    printf("%d", j);

}
