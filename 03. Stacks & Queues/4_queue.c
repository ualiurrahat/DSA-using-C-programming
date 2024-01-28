// Queue Data Structure....
// FIFO-> First In First Out.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Q_SIZE 5

typedef struct
{
    int data[Q_SIZE + 1]; // array size would be 1 greater than total no. of elements.
    int head;
    int tail;
} Queue;

void enQueue(Queue *q, int item)
{
    // checking if queue is full
    if ((q->tail + 1) % (Q_SIZE + 1) == q->head)
    {
        printf("Queue is full\n");
        return;
    }
    q->data[q->tail] = item;
    q->tail = (q->tail + 1) % (Q_SIZE + 1);
}

int deQueue(Queue *q)
{
    int item;

    // checking if queue is empty.
    if (q->tail == q->head)
    {
        printf("Queue is emtpy\n");
        return -1;
    }
    item = q->data[q->head];
    q->head = (q->head + 1) % (Q_SIZE + 1);
    return item;
}

void initQueue(Queue *q)
{
    q->head = 0;
    q->tail = 0;
}

int main()
{
    Queue q;
    int item;

    // initializing the queue.
    initQueue(&q);

    // adding elements ...enquement.

    enQueue(&q, 1);
    printf("tail = %d\n", q.tail);

    enQueue(&q, 2);
    printf("tail = %d\n", q.tail);

    enQueue(&q, 3);
    printf("tail = %d\n", q.tail);

    enQueue(&q, 4);
    printf("tail = %d\n", q.tail);

    enQueue(&q, 5);
    printf("tail = %d\n", q.tail);

    enQueue(&q, 6);
    printf("tail = %d\n", q.tail);

    // removing elements ... dequement.

    printf("beginning head = %d\n", q.head);

    item = deQueue(&q);
    printf("item = %d, head = %d\n", item, q.head);

    item = deQueue(&q);
    printf("item = %d, head = %d\n", item, q.head);

    item = deQueue(&q);
    printf("item = %d, head = %d\n", item, q.head);

    item = deQueue(&q);
    printf("item = %d, head = %d\n", item, q.head);

    item = deQueue(&q);
    printf("item = %d, head = %d\n", item, q.head);

    
    item = deQueue(&q);
    printf("item = %d, head = %d\n", item, q.head);

    return 0;
}