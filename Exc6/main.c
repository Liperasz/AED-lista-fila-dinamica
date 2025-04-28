//
// Created by liperasz on 27/04/25.
//
#include "Exc6.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    Queue *queue = createQueue();
    Queue *queue2 = createQueue();
    Queue *queue3 = createQueue();

    insertQueue(queue, 1);
    insertQueue(queue, 5);
    insertQueue(queue, 9);
    insertQueue(queue, 15);
    insertQueue(queue, 120);
    printQueue(queue);

    insertQueue(queue2, 2);
    insertQueue(queue2, 6);
    insertQueue(queue2, 10);
    insertQueue(queue2, 14);
    insertQueue(queue2, 15);
    printQueue(queue2);

    InsertThirdQueue(queue, queue2, queue3);
    printQueue(queue3);

    destroyQueue(queue);
    destroyQueue(queue2);
    destroyQueue(queue3);

    return 0;
}