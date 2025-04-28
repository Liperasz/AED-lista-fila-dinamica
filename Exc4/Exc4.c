//
// Created by liperasz on 27/04/25.
//

#include "Exc4.h"
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
/*Tive que alterar a lógica nesse, além de verificar se a fila é nula, tem que verificar se o primeiro elemento
 * é nulo também. Após isso, cria um novo elemento com que aponta para o começo da fila, e utiliza dele e mais um
 * auxiliar para ir excluindo todos os elementos, até que novamente ele se iguale ao ponteiro que aponta para o primeiro.
 * OBS:  tive que trocar o uso do while para o do while, caso usasse apenas while, a função nunca seria executada.
 */


int insertQueue(Queue *queue, float data) {

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
//Aqui a única alteração necessária foi fazer com que o próximo valor do último elemento aponte de volta para o primeiro
//Fazendo assim uma fila circular.

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
//Aqui já houve uma complicação menor, pois da forma convencional não funcionaria, afinal o valor do primeiro elemento
//nunca iria ser nulo, então primeiro verifica-se se existe apenas um elemento, caso seja apenas 1, ele torna tanto o
//Primeiro ponteiro como o ultimo com valor NULL, indicando que a fila agora está vazia.
//Caso não seja nulo, ele apenas faz a alteração normal dizendo que agora o novo primeiro elemento, é o proximo do antigo
//Primeiro, e faz com que o próximo do ultimo elemento seja o novo primeiro.

void printQueue(Queue *queue) {

    if (queue != NULL && queue->first != NULL) {

        Element *element = queue->first;

        do {

            printf("Valor: %.1f\n", element->data);
            element = element->next;
        } while (element != queue->first);

    }
}
//A função se aproveita do fato dela ser cirular para a verificação, ao invés de ter que chegar a um elemento nulo,
//basta verificar se o elemento já chegou de volta ao ponteiro que aponta para o primeiro elemento.

int CutInLine(Queue *queue, float data) {

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
//Se a fila está vazia, a função fará o ponteiro que aponta para o primeiro, para o ultimo, e para o próximo depois do ultimo,
//Todos apontaram para o mesmo novo elemento. Agora, caso já exista um elemento, a função fará o proximo elemento do ultimo
//apontar para o novo elemento invés do atual primeiro, proximo do novo elemento apontará para o atual primeiro elemento,
//e para finalizar, o primeiro elemento apontará para esse novo elemento.