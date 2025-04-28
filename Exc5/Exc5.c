//
// Created by liperasz on 27/04/25.
//

#include "Exc5.h"
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

int insertQueue(Queue *queue, Airplane data) {

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

int CutInLine(Queue *queue, Airplane data) {

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

int sizeQueue(Queue *queue) {

    if (queue == NULL) {
        return 0;
    }

    return queue->size;
}

void AirplaneList(Queue *queue, int x) {

    if (queue == NULL) {
        return;
    }

    if (queue->first == NULL) {
        printf("\nNo Airplanes for Takeoff\n");
        return;
    }


    switch (x) { //Verifica se o tipo da lista é para decolagem ou é a lista de espera

        case 1:

            printf ("\n||------------------------------------------------||\n");
            printf ("||  LIST OF AIRPLANES FOR TAKEOFF  ||  SIZE: %d  ||\n\n\n", sizeQueue(queue));
            break;

        case 2:

            printf ("\n||------------------------------------------------||\n");
            printf ("||  AIRPLANES IN WAITING LIST  ||  SIZE: %d  ||\n\n\n", sizeQueue(queue));
            break;

        default:

            printf("Unknown error");
            return;


    }



    Element *element = queue->first;
    int i = 1;
    do {
        printf ("\n||------------------------------------------------||\n");
        printf("Airplane %d: \n", i);
        printf("\n\tID: %d", element->data.ID);
        printf("\n\tModel: %s", element->data.model);
        printf("\n\tCapacity: %d", element->data.capacity);
        printf ("\n||------------------------------------------------||\n");

    } while (element != queue->first);

}
//Formula padrão par printar uma fila circular, apenas verificar até o ponteiro se igualar ao ponteiro do começo da fila

void AuthorizeTakeoff(Queue *queue) {

    if (queue == NULL) {
        return;
    }

    if (queue->first == NULL) {
        printf("\nNo Airplanes for Takeoff\n");
        return;

    }

    printf ("\n||------------------------------------------------||\n");
    printf("\nAuthorizing takeoff...\n");
    printf("\nAirplane: ID: %d", queue->first->data.ID);
    printf("\n          Model: %s", queue->first->data.model);
    printf("\n          Capacity: %d", queue->first->data.capacity);

    if (removeQueue(queue) == 1) { //Verifica se deu certo a remoção
        printf("\n\nAirplane took off\n");
    }
    else {
        printf("\n\nError in taking off\n");
    }
}

void AddAirplane(Queue *queue, Airplane data, int x) {

    if (queue == NULL) {
        return;
    }

    switch (x) { //Verifica se o tipo da lista é para decolagem ou é a lista de espera

        case 1:

            printf ("\n||------------------------------------------------||\n");
            printf("\nAdding airplane in takeoff list...");
            if (insertQueue(queue, data) == 1) { //Verifica se deu certo adicionar
                printf("\n\nAirplane added in takeoff list\n");
            } else {
                printf("\n\nError in adding airplane\n");
            }

            break;

        case 2:

            printf ("\n||------------------------------------------------||\n");
            printf("\nAdding airplane in waiting list...");
            if (insertQueue(queue, data) == 1) { //Verifica se deu certo adicionar
                printf("\n\nAirplane added in waiting list\n");
            } else {
                printf("\n\nError in adding airplane\n");
            }

            break;

        default:

            printf("Unknown error");

    }
}

void VerifyAirplane(Queue *queue, int x) {

    if (queue == NULL) {
        return;
    }

    switch (x) { //Verifica se o tipo da lista é para decolagem ou é a lista de espera

        case 1:

            if (queue->first == NULL) {
                printf("\nNo Airplanes for Takeoff\n");
            } else {
                printf("\nAirplane for takeoff: ID: %d", queue->first->data.ID);
                printf("\n                          Model: %s", queue->first->data.model);
                printf("\n                          Capacity: %d", queue->first->data.capacity);
            }

        break;

        case 2:

            if (queue->first == NULL) {
                printf("\nNo Airplanes in waiting list\n");
            } else {
                printf("\nAirplane in waiting list: ID: %d", queue->first->data.ID);
                printf("\n                          Model: %s", queue->first->data.model);
                printf("\n                          Capacity: %d", queue->first->data.capacity);
            }

        break;

        default:

            printf("Unknown error");

    }
}

void MoveAirplane(Queue *wq, Queue *tq) {

    if (wq == NULL || tq == NULL) {
        return;
    }

    if (wq->first == NULL) {
        printf("\nNo Airplanes in waiting list\n");
        return;
    }

    if (insertQueue(tq, wq->first->data) == 1 && removeQueue(wq) == 1) { //Verifica se ambas operações deram certo

        printf("\nAirplane moved from waiting to takeoff list\n");
    } else {

        printf("\nError in moving airplane\n");
    }

}
//Adiciona o primeiro avião da fila de espera para a fila de decolagem, depois remove da fila de espera


int menu() {

    printf ("\n||------------------------------------------------||\n");
    printf ("\n\t||  AIRPORT MENU  ||\n");
    printf("1 - List airplanes in takeoff queue\n");
    printf("2 - List airplanes in waiting queue\n");
    printf("3 - Authorize takeoff\n");
    printf("4 - Add airplane to takeoff queue\n");
    printf("5 - Add airplane to waiting queue\n");
    printf("6 - Show all airplanes in takeoff queue\n");
    printf("7 - Show all airplanes in waiting queue\n");
    printf("8 - Show first airplane in takeoff queue\n");
    printf("9 - Show first airplane in waiting queue\n");
    printf("10 - Move airplane from waiting to takeoff queue\n");
    printf("0 - Exit\n");
    printf("Select an option: ");

    int option;
    scanf("%d", &option);

    return option;
}

/*
 * Esse exercício não tem muito o que explicar no quesito lógica, são basicamente insert e remove nas filas, com uma
 * gourmetização para deixar mais bonito
 */