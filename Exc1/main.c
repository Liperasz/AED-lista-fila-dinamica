//
// Created by liperasz on 24/04/25.
//
#include <stdio.h>
#include "Exc1.h"

int main() {

    Student a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};

    Queue *q1 = createQueue();
    Queue *q2 = createQueue();

    for(int i = 0; i < 4; i++) {
        insertQueue(q1,a[i]);
    }

    separate(q1,q2,1);

    printf("Queue 1: \n\n\n");
    printQueue(q1);

    printf("\n\n\n");
    printf("Queue 2: \n\n\n");
    printQueue(q2);

    destroyQueue(q1);
    destroyQueue(q2);

    return 0;
}