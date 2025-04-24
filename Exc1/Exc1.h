//
// Created by liperasz on 24/04/25.
//

#ifndef EXC1_H
#define EXC1_H

typedef struct {

    int id;
    char name[30];
    float g1,g2,g3;

} Student;

typedef struct element {

    Student data;
    struct element *next;

} Element;

typedef struct {

    Element *first;
    Element *last;
    int size;

} Queue;

Queue *createQueue();
void destroyQueue(Queue *queue);
int consultQueue(Queue *queue, Student *data);
int insertQueue(Queue *queue, Student data);
int removeQueue(Queue *queue);
int sizeQueue(Queue *queue);
int isEmptyQueue(Queue *queue);
int isFullQueue(Queue *queue);
void printQueue(Queue *queue);

int separate(Queue *q1, Queue *q2, int id);

#endif //EXC1_H
