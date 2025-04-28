//
// Created by liperasz on 27/04/25.
//
#include <stdio.h>
#include <stdlib.h>
#include "Exc3.h"

int main() {

    Student a[4] = {
        {2, "Andre", 9.5, 7.8, 8.5},
        {4, "Ricardo", 7.5, 8.7, 6.8},
        {1, "Bianca", 9.7, 6.7, 8.4},
        {3, "Ana", 5.7, 6.1, 7.4}
    };

    Queue *q = createQueue();

    for (int i = 0; i < 4; i++) {
        insertQueue(q, a[i]);
    }

    printQueue(q);
    printf("\n\n\n");

    TurnQueueOver(q);

    printQueue(q);

    destroyQueue(q);

    return 0;
}
