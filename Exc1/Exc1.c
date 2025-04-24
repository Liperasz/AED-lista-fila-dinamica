//
// Created by liperasz on 24/04/25.
//
#include <stdio.h>
#include "Exc1.h"

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

int separate(Queue *q1, Queue *q2, int id) {

    if (q1 == NULL || q2 == NULL || q1->first == NULL) { //Verifica se a fila 1 existe e possui elementos, e verifica se a fila 2 não é nula
        return 0;
    }

    Element *element = q1->first;

    for (int i = 0; i < q1->size; i++) { //Se necessário, percorre até o final da fila 1

        if (element->data.id == id && element->next != NULL) { //Se encontrar o ID na fila 1, e o próximo elemento não for nulo, ele fará a separação

            q2->first = element->next; //Primeiro elemento da fila 2 igual ao próximo elemento
            q2->last = q1->last; //Ultimo elemento da fila 2 igual ao final da fila 1
            q1->last = element; //Altera o final da fila 1 para o elemento atual
            q1->last->next = NULL; //Aponta o proximo elemento da fila 1 para NULL, finalizando a separação das filas

            //Algoritmo para fazer a contagem da nova quantidade de elementos de ambas as filas
            int quant = 0;
            element = q1->first;
            while (element->next != NULL) {
                quant++;
                element = element->next;
            }
            q1->size = quant;

            quant = 0;
            element = q2->first;
            while (element->next != NULL) {
                quant++;
                element = element->next;
            }
            q2->size = quant;

            return 1; //Retorna 1 para mudança completa

        }

        element = element->next; //Caso não encontre as condições, avança para o próximo elemento

    }

    return 0; //Retorna 0 caso não tenha feito nenhuma separação de filas

}
/*A ideia é da função é alterar apenas os ponteiros finais e o inicial da segunda, afinal, a unica coisa que une
 *os elementos são os ponteiros, então basta apenas separar na parte correta, fazendo a outra fila apontar para o elemento
 */