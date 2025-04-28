//
// Created by liperasz on 27/04/25.
//

#include "Exc6.h"
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

int InsertThirdQueue(Queue *queue1, Queue *queue2, Queue *queue3) {

    if (queue1 == NULL || queue2 == NULL || queue3 == NULL) {
        return 0;
    }

    if (queue1->first == NULL && queue2->first == NULL) { //Se as duas filas estiverem vazias, retorna 0
        printf("Both queues are empty\n");
        return 0;
    }

    if (queue1->first == NULL) { //Se apenas a fila 1 estiver vazia, ele insere os valores da fila 2 na fila 3

        Element *element = queue2->first;
        do {

            insertQueue(queue3, element->data);
            element = element->next;

        } while (queue2->first != element);
        return 1;

    }

    if (queue2->first == NULL) { //Se apenas a fila 2 estiver vazia, ele insere os valores da fila 1 na fila 3

        Element *element = queue1->first;
        do {

            insertQueue(queue3, element->data);
            element = element->next;
        } while (queue1->first != element);

        return 1;
    }


    Element *element1 = queue1->first;
    Element *element2 = queue2->first;
    int i = 0;
    int j = 0;

    do { //Caso as duas tenham elementos

        if (element1->data < element2->data) { //Verifica se o elemento é menor que o da segunda fila

            insertQueue(queue3, element1->data); //Se for menor, insere o da primeira fila

            element1 = element1->next; //Avança para o próximo elemento
            i++; //Incrementa a quantidade

            if (i == queue1->size) { //Se i chegar no tamanho da fila, encerra o loop while (significa que já percorreu todos os elementos)
                break;
            }

        } else {

            insertQueue(queue3, element2->data); //Se for maior ou igual, adiciona o elemento da segunda na terceira fila

            element2 = element2->next; //Avança pro próximo
            j++; //Aumenta a quantidade

            if (j == queue2->size) { //Se chegou no final da fila, da o break
                break;
            }

        }


    } while (1);

    //Realiza o while para a fila que ainda tenha elementos a ser adicionado.
    //Caso a fila 2 seja maior ou igual a fila 1, apenas o segundo while será executado, caso a 1 seja a maior, apenas o primeiro
    while (element1 != queue1->first) {
        insertQueue(queue3, element1->data);
        element1 = element1->next;
    }

    while (element2 != queue2->first) {
        insertQueue(queue3, element2->data);
        element2 = element2->next;
    }

    return 1;
}