#include <stdio.h>
#include "Exc2.h"

int main() {
    Student a[4] = {
        {2, "Andre", 9.5, 7.8, 8.5},
        {4, "Ricardo", 7.5, 8.7, 6.8},
        {1, "Bianca", 9.7, 6.7, 8.4},
        {3, "Ana", 5.7, 6.1, 7.4}
    };

    Queue *q1 = createQueue();

    for (int i = 0; i < 4; i++) {
        insertQueue(q1, a[i]);
    }

    printQueue(q1);
    printf("\n\n\n");

    removeQueue(q1);

    printQueue(q1);
    printf("\n\n\n");

    destroyQueue(q1);

    SuperQueue *sq = createSuperQueue();

    Queue *q2 = createQueue();
    Queue *q3 = createQueue();

    insertQueue(q2, a[0]);
    insertQueue(q3, a[1]);

    insertSuperQueue(sq, q2);
    insertSuperQueue(sq, q3);

    printSuperQueue(sq);
    printf("\n\n\n");

    removeSuperQueue(sq);

    printSuperQueue(sq);
    printf("\n\n\n");

    destroySuperQueue(sq);

    QueueOfStacks *qos = createQueueOfStacks();

    Stack *s1 = createStack();
    Stack *s2 = createStack();

    insertStack(s1, a[2]);
    insertStack(s2, a[3]);

    insertQueueOfStacks(qos, s1);
    insertQueueOfStacks(qos, s2);

    printQueueOfStacks(qos);
    printf("\n\n\n");

    removeQueueOfStacks(qos);

    printQueueOfStacks(qos);
    printf("\n\n\n");

    destroyQueueOfStacks(qos);

    StackOfQueues *soq = createStackOfQueues();
    Queue *q4 = createQueue();
    Queue *q5 = createQueue();

    insertQueue(q4, a[0]);
    insertQueue(q5, a[1]);

    insertStackOfQueues(soq, q4);
    insertStackOfQueues(soq, q5);

    printStackOfQueues(soq);
    printf("\n\n\n");

    removeStackOfQueues(soq);

    printStackOfQueues(soq);
    printf("\n\n\n");

    destroyStackOfQueues(soq);

    return 0;
}
