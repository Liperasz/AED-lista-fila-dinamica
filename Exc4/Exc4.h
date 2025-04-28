//
// Created by liperasz on 27/04/25.
//

#ifndef EXC4_H
#define EXC4_H

typedef struct element{

    float data;
    struct element *next;

} Element;

typedef struct {

    Element *first;
    Element *last;
    int size;

} Queue;

Queue *createQueue();
void destroyQueue(Queue *queue);
int insertQueue(Queue *queue, float data);
int removeQueue(Queue *queue);


void printQueue(Queue *queue);
int CutInLine(Queue *queue, float data);
#endif //EXC4_H
