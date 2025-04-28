//
// Created by liperasz on 27/04/25.
//
#include "Exc4.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    Queue *queue = createQueue();

    insertQueue(queue, 1.1);
    insertQueue(queue, 2.2);
    insertQueue(queue, 3.3);

    printQueue(queue);
    printf("\n\n\n");

    removeQueue(queue);
    printQueue(queue);
    printf("\n\n\n");


    CutInLine(queue, 9.9);
    printQueue(queue);
    printf("\n\n\n");


    CutInLine(queue, 8.8);
    printQueue(queue);
    printf("\n\n\n");


    destroyQueue(queue);
    printf("\n\n\n");

    return 0;
}