//
// Created by liperasz on 27/04/25.
//

#ifndef EXC7_H
#define EXC7_H

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

int Reverse(Queue *queue);

#endif //EXC7_H
