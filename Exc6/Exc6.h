//
// Created by liperasz on 27/04/25.
//

#ifndef EXC6_H
#define EXC6_H

typedef struct element{

    int data;
    struct element *next;

} Element;

typedef struct {

    Element *first;
    Element *last;
    int size;

} Queue;

Queue *createQueue();
void destroyQueue(Queue *queue);
int insertQueue(Queue *queue, int data);
int removeQueue(Queue *queue);
void printQueue(Queue *queue);

int InsertThirdQueue(Queue *queue1, Queue *queue2, Queue *queue3);


#endif //EXC6_H
