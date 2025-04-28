//
// Created by liperasz on 25/04/25.
//

#include <stdio.h>
#include "Exc3.h"

#include <stdlib.h>

Queue *createQueue() {

    Queue *queue = malloc(sizeof(Queue));
    if (queue != NULL) {
        queue->first = NULL;
        queue->last = NULL;
        queue->size = 0;

    }

    return queue;

}

void destroyQueue(Queue *queue) {

    if (queue != NULL) {
        while (queue->first != NULL) {
            Element *element = queue->first;
            queue->first = queue->first->next;
            free(element);
        }
    }
    free(queue);
}

int consultQueue(Queue *queue, Student *data) {

    if (queue == NULL || queue->first == NULL) {
        return 0;
    }

    *data = queue->first->data;
    return 1;

}

int insertQueue(Queue *queue, Student data) {

    if (queue == NULL) {
        return 0;
    }

    Element *element = malloc(sizeof(Element));
    if (element == NULL) {
        return 0;
    }

    element->data = data;
    element->next = NULL;

    if (queue->first == NULL) {
        queue->first = element;
    }
    else {
        queue->last->next = element;
    }

    queue->last = element;
    queue->size++;
    return 1;
}

int removeQueue(Queue *queue) {

    if (queue == NULL || queue->first == NULL) {
        return 0;
    }

    Element *element = queue->first;
    queue->first = queue->first->next;

    if (queue->first == NULL) {
        queue->last = NULL;
    }

    free(element);
    queue->size--;
    return 1;

}

int sizeQueue(Queue *queue) {

    if (queue == NULL) {
        return 0;
    }

    return queue->size;
}

int isEmptyQueue(Queue *queue) {

    if (queue == NULL || queue->first == NULL) {
        return 1;
    }
    return 0;
}

int isFullQueue(Queue *queue) {
    return 0;
}

void printQueue(Queue *queue) {

    if (queue == NULL) {
        return;
    }

    Element *element = queue->first;

    while(element != NULL){
        printf("Matricula: %d\n",element->data.id);
        printf("Nome: %s\n",element->data.name);
        printf("Notas: %.1f %.1f %.1f\n",element->data.g1,
                                   element->data.g2,
                                   element->data.g3);
        printf("-------------------------------\n");
        element = element->next;
    }

}



SuperQueue *createSuperQueue() {

    SuperQueue *sq = malloc(sizeof(SuperQueue));
    if (sq != NULL) {
        sq->first = NULL;
        sq->last = NULL;
        sq->size = 0;
    }

    return sq;
}

void destroySuperQueue(SuperQueue *sq) {

    if (sq != NULL) {

        while (sq->first != NULL) {
            Queue *q = sq->first;
            sq->first = sq->first->next;
            destroyQueue(q);
        }
        free(sq);

    }
}

int insertSuperQueue(SuperQueue *sq, Queue *q) {

    if (sq == NULL) {
        return 0;
    }

    Queue *element = q;
    element->next = NULL;

    if (sq->first == NULL) {
        sq->first = element;
    }
    else {
        sq->last->next = element;
    }

    sq->last = element;
    sq->size++;

    return 1;
}

int removeSuperQueue(SuperQueue *sq) {

    if (sq == NULL || sq->first == NULL) {
        return 0;
    }

    Queue *element = sq->first;
    sq->first = sq->first->next;
    if (sq->first == NULL) {
        sq->last = NULL;
    }

    destroyQueue(element);
    sq->size--;

    return 1;
}

void printSuperQueue(SuperQueue *sq) {

    if (sq != NULL) {

        Queue *queue = sq->first;
        int i = 1;

        while (queue != NULL) {

            printf("Queue %d\n\n\n", i);
            printQueue(queue);
            queue = queue->next;
            i++;

        }
    }
}


Stack* createStack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    if (stack != NULL) {
        *stack = NULL;
    }

    return stack;
}

void destroyStack(Stack* stack) {
    if (stack != NULL) {
        Element* element;
        while ((*stack) != NULL) {
            element = *stack;
            *stack = (*stack)->next;
            free(element);
        }
        free(stack);
    }
}

int consultTopStack(Stack* stack, Student *student) {
    if (stack == NULL)
        return 0;
    if ((*stack) == NULL)
        return 0;
    *student = (*stack)->data;
    return 1;
}

int insertStack(Stack* stack, Student student) {
    if (stack == NULL)
        return 0;
    Element* element;
    element = (Element*) malloc(sizeof(Element));
    if (element == NULL)
        return 0;
    element->data = student;
    element->next = (*stack);
    *stack = element;
    return 1;
}

int removeStack(Stack* stack) {
    if (stack == NULL)
        return 0;
    if ((*stack) == NULL)
        return 0;
    Element* element = *stack;
    *stack = element->next;
    free(element);
    return 1;
}

int sizeStack(Stack* stack) {
    if (stack == NULL)
        return 0;
    int count = 0;
    Element* element = *stack;
    while (element != NULL) {
        count++;
        element = element->next;
    }
    return count;
}

int isFullStack(Stack* stack) {
    return 0;
}

int isEmptyStack(Stack* stack) {
    if (stack == NULL)
        return 1;
    if (*stack == NULL)
        return 1;
    return 0;
}

void printStack(Stack* stack) {
    if (stack == NULL)
        return;
    Element* element = *stack;
    while (element != NULL) {
        printf("Matricula: %d\n", element->data.id);
        printf("Nome: %s\n", element->data.name);
        printf("Notas: %.1f %.1f %.1f\n", element->data.g1,
                                          element->data.g2,
                                          element->data.g3);
        printf("-------------------------------\n");
        element = element->next;
    }
}

QueueOfStacks *createQueueOfStacks() {

    QueueOfStacks *qos = malloc(sizeof(QueueOfStacks));
    if (qos != NULL) {
        qos->first = NULL;
        qos->last = NULL;
        qos->size = 0;
    }

    return qos;

}

void destroyQueueOfStacks(QueueOfStacks *qos) {

    if (qos != NULL) {

        while (qos->first != NULL) {

            Stack *stack = qos->first->stack;
            qos->first = qos->first->next;
            destroyStack(stack);
        }
        free(qos);
    }

}

int insertQueueOfStacks(QueueOfStacks *qos, Stack *stack) {

    if (qos == NULL) {
        return 0;
    }

    ElementStack *element = malloc(sizeof(ElementStack));

    if (element == NULL) {
        return 0;
    }

    element->stack = stack;
    element->next = NULL;

    if (qos->first == NULL) {
        qos->first = element;
    }
    else {
        qos->last->next = element;
    }
    qos->last = element;
    qos->size++;

    return 1;

}

int removeQueueOfStacks(QueueOfStacks *qos) {

    if (qos == NULL || qos->first == NULL) {
        return 0;
    }

    ElementStack *element = qos->first;

    qos->first = qos->first->next;

    if (qos->first == NULL) {
        qos->last = NULL;
    }

    destroyStack(element->stack);
    free(element);
    qos->size--;

    return 1;

}

void printQueueOfStacks(QueueOfStacks *qos) {

    if (qos != NULL) {

        ElementStack *element = qos->first;

        while (element != NULL) {

            printStack(element->stack);
            printf("\n");
            element = element->next;
            
        }
        
    }
    
}

StackOfQueues *createStackOfQueues() {

    StackOfQueues *soq = malloc(sizeof(StackOfQueues));
    if (soq != NULL) {
        *soq = NULL;
    }

    return soq;
    
}

void destroyStackOfQueues(StackOfQueues *soq) {

    if (soq != NULL) {

        while (*soq != NULL) {

            Queue* queue = *soq;
            *soq = (*soq)->next;
            destroyQueue(queue);
            
        }

        free(soq);
        
    }
    
}

int insertStackOfQueues(StackOfQueues *soq, Queue *queue) {

    if (soq == NULL) {
        return 0;  
    }

    Queue *element = queue;
    element->next = *soq;
    *soq = element;

    return 1;
    
}

int removeStackOfQueues(StackOfQueues *soq) {

    if (soq == NULL || *soq == NULL) {
        return 0;
    }

    Queue *element = *soq;
    *soq = (*soq)->next;
    destroyQueue(element);

    return 1;

}

void printStackOfQueues(StackOfQueues *soq) {

    if (soq != NULL) {

        Queue *element = *soq;

        while (element != NULL) {

            printQueue(element);
            printf("\n");
            element = element->next;

        }

    }

}

int TurnQueueOver(Queue *q) {

    if (q == NULL || q->first == NULL) {
        return 0;
    }

    Stack *stack = createStack();

    if (stack == NULL) {
        return 0;
    }

    while (q->first != NULL) {

        insertStack(stack, q->first->data);
        removeQueue(q);

    }

    while (*stack != NULL) {

        insertQueue(q, (*stack)->data);
        removeStack(stack);

    }

    destroyStack(stack);

    return 1;
}
//A lógica usada foi inserir o elemento da fila na pilha, e logo em seguida remove-lo, para que assim não haja erro na
//memória posteriormente. O algoritmo fará isso até que acabe os elementos da fila, fazendo com que no final seja
//uma fila vazia. Depois disso, adicionaremos os valores da pilha de volta na fila, novamente até o final, e novamente
//excluindo os elementos, após tudo, a própria pilha é excluida, deixando apenas a fila em ordem inversa.
//A pilha é criada dentro da própria função, afinal, como ela precisa ser vazia, não faz sentido passa-la como parâmetro