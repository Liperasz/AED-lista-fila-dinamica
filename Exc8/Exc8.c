//
// Created by liperasz on 27/04/25.
//

#include "Exc8.h"
#include <stdio.h>
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

        if (queue->first != NULL) {

            Element *element1 = queue->first;

            do {

                Element *element2 = element1;
                element1 = element1->next;
                free(element2);

            } while (element1 != queue->first);

        }

        free(queue);
    }
}

int insertQueue(Queue *queue, int data) {

    if (queue == NULL) {
        return 0;
    }

    Element *element = malloc(sizeof(Element));
    if (element == NULL) {
        return 0;
    }

    element->data = data;

    if (queue->first == NULL) {
        queue->first = element;
    }
    else {
        queue->last->next = element;
    }

    queue->last = element;
    queue->last->next = queue->first;
    queue->size++;
    return 1;
}

int removeQueue(Queue *queue) {

    if (queue == NULL || queue->first == NULL) {
        return 0;
    }

    Element *element = queue->first;

    if (queue->first == queue->last) { //Verifica se existe apenas um elemento

        queue->first = NULL;
        queue->last = NULL;
        queue->size--;
        free(element);
        return 1;

    }

    queue->first = queue->first->next;
    queue->last->next = queue->first;

    free(element);
    queue->size--;
    return 1;

}

void printQueue(Queue *queue) {

    if (queue != NULL && queue->first != NULL) {

        Element *element = queue->first;

        do {

            printf("Valor: %d\n", element->data);
            element = element->next;
        } while (element != queue->first);

    }
}

int CutInLine(Queue *queue, int data) {

    if (queue == NULL) {
        return 0;
    }

    Element *element = malloc(sizeof(Element));
    if (element == NULL) {
        return 0;
    }

    element->data = data;

    if (queue->first == NULL) {
        queue->first = element;
        queue->last = element;
        queue->last->next = queue->first;
        queue->size++;
        return 1;
    }

    queue->last->next = element;
    element->next = queue->first;
    queue->first = element;
    queue->size++;
    return 1;
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

int consultQueue(Queue *queue, int *data) {

    if (queue == NULL || queue->first == NULL) {
        return 0;
    }

    *data = queue->first->data;
    return 1;

}

int sizeQueue(Queue *queue) {

    if (queue == NULL) {
        return 0;
    }

    return queue->size;
}

int menu() {

    printf("\nSelecione uma opção:\n\n");
    printf("0 - Sair\n");
    printf("1 - Inicializar filas\n");
    printf("2 - Verificar se fila esta vazia\n");
    printf("3 - Verificar se fila esta cheia\n");
    printf("4 - Enfileirar elemento\n");
    printf("5 - Desenfileirar elemento\n");
    printf("6 - Ler elemento no inicio da fila\n");
    printf("7 - Comparar qual fila possui mais elementos\n");
    printf("8 - Furar fila\n");

    int option;
    scanf("%d", &option);
    return option;

}