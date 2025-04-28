//
// Created by liperasz on 27/04/25.
//
#include "Exc7.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    Queue *queue = createQueue();

    insertQueue(queue, 1);
    insertQueue(queue, 5);
    insertQueue(queue, 9);
    insertQueue(queue, 15);
    insertQueue(queue, 120);
    printQueue(queue);

    Reverse(queue);
    printQueue(queue);

    destroyQueue(queue);

    return 0;
}