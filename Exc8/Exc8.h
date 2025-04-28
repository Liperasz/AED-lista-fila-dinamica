//
// Created by liperasz on 27/04/25.
//

#ifndef EXC8_H
#define EXC8_H

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
int CutInLine(Queue *queue, int data);
int isEmptyQueue(Queue *queue);
int isFullQueue(Queue *queue);
int consultQueue(Queue *queue, int *data);
int sizeQueue(Queue *queue);
int menu();

#endif //EXC8_H
