//
// Created by liperasz on 25/04/25.
//

#ifndef EXC2_H
#define EXC2_H

typedef struct {

    int id;
    char name[30];
    float g1,g2,g3;

} Student;

typedef struct element {

    Student data;
    struct element *next;

} Element;

typedef struct queue {

    Element *first;
    Element *last;
    int size;
    struct queue *next;

} Queue;

typedef struct {

    Queue *first;
    Queue *last;
    int size;

} SuperQueue;

typedef Element* Stack;

typedef struct stack{

    Stack *stack;
    struct stack *next;

} ElementStack;

typedef struct {

    ElementStack *first;
    ElementStack *last;
    int size;

} QueueOfStacks;

typedef Queue* StackOfQueues;

Queue *createQueue();
void destroyQueue(Queue *queue);
int consultQueue(Queue *queue, Student *data);
int insertQueue(Queue *queue, Student data);
int removeQueue(Queue *queue);
int sizeQueue(Queue *queue);
int isEmptyQueue(Queue *queue);
int isFullQueue(Queue *queue);
void printQueue(Queue *queue);

//Queue of queues

SuperQueue *createSuperQueue();
void destroySuperQueue(SuperQueue *sq);
int insertSuperQueue(SuperQueue *sq, Queue *q);
int removeSuperQueue(SuperQueue *sq);
void printSuperQueue(SuperQueue *sq);

//Stacks

Stack* createStack();
void destroyStack(Stack* stack);
int consultTopStack(Stack* stack, Student *student);
int insertStack(Stack* stack, Student student);
int removeStack(Stack* stack);
int sizeStack(Stack* stack);
int isEmptyStack(Stack* stack);
int isFullStack(Stack* stack);
void printStack(Stack* stack);

//Queue of stacks

QueueOfStacks *createQueueOfStacks();
void destroyQueueOfStacks(QueueOfStacks *qos);
int insertQueueOfStacks(QueueOfStacks *qos, Stack *stack);
int removeQueueOfStacks(QueueOfStacks *qos);
void printQueueOfStacks(QueueOfStacks *qos);

//Stack of queues

StackOfQueues *createStackOfQueues();
void destroyStackOfQueues(StackOfQueues *soq);
int insertStackOfQueues(StackOfQueues *soq, Queue *queue);
int removeStackOfQueues(StackOfQueues *soq);
void printStackOfQueues(StackOfQueues *soq);


int TurnQueueOver(Queue *q);


#endif //EXC2_H
