//
// Created by liperasz on 27/04/25.
//

#ifndef EXC5_H
#define EXC5_H

typedef struct {

    int ID;
    char model[30];
    int capacity;

} Airplane;

typedef struct element{

    Airplane data;
    struct element *next;

} Element;

typedef struct {

    Element *first;
    Element *last;
    int size;

} Queue;

Queue *createQueue();
void destroyQueue(Queue *queue);
int insertQueue(Queue *queue, Airplane data);
int removeQueue(Queue *queue);
int CutInLine(Queue *queue, Airplane data);
int sizeQueue(Queue *queue);

void AirplaneList(Queue *queue, int x);
void AuthorizeTakeoff(Queue *queue);
void AddAirplane(Queue *queue, Airplane data, int x);
void VerifyAirplane(Queue *queue, int x);
void MoveAirplane(Queue *wq, Queue *tq);

int menu();

#endif //EXC5_H
