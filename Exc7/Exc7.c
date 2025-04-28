//
// Created by liperasz on 27/04/25.
//

#include "Exc7.h"
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

int Reverse(Queue *queue) {

    if (queue == NULL || queue->first == NULL) { //Verifica se é nulo ou vazio
        return 0;
    }

    Element *current = queue->first; //Cria um elemento para o valor atual
    Element *previous = queue->last; //Um para o valor anterior
    Element *next = NULL; //Um para o próximo valor

    do {

        next = current->next; //faz o próximo valor ser equivalente ao proximo da fila atual e próximo que irá atualizar
        current->next = previous; //O ponteiro que aponta para o próximo valor do elemento atual, vai apontar para trás
        previous = current; //Vai atualizar os ponteiros, fazendo com que o anterior passe para o atual,
        current = next; //e o atual para o próximo

    } while (current != queue->first);

    queue->first = queue->last; //Faz com que o ultimo seja o antigo primeiro
    queue->last = current; //Faz com que o primeiro seja o antigo ultimo

    return 1;
}
/*A lógica baseia em sempre guardar 3 ponteiros, um para o próximo para que possa avançar sem problemas e continuar a reversão,
 *um para o anterior, e um para o atual. A mágica acontece quando o ponteiro atual invés de apontar para o próximo, aponta para o anterior,
 *invertendo a ordem dos ponteiros sem inventer os valores. Então, no final, apenas altera o ponteiro que era o ultimo passa a apontar
 *para o antigo primeiro, e vice-versa
 */