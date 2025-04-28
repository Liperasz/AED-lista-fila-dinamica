//
// Created by liperasz on 27/04/25.
//
#include "Exc8.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    Queue *queue1 = createQueue();
    Queue *queue2 = createQueue();

    int option, choose, value;

    while (1) {

        option = menu();

        switch (option) {

            case 0:

                printf("\nEncerrando programa...\n");
                destroyQueue(queue1);
                destroyQueue(queue2);
                return 0;

            case 1:

                //Destruirá as filas caso jã existam
                destroyQueue(queue1);
                destroyQueue(queue2);

                queue1 = createQueue();
                queue2 = createQueue();

                printf("Filas inicializadas.\n");
                break;

            case 2:

                printf("Escolha a fila para verificar se esta vazia (1 ou 2): ");
                scanf("%d", &choose);

                if ((choose == 1 && isEmptyQueue(queue1) == 1) || (choose == 2 && isEmptyQueue(queue2) == 1)) {
                    printf("\nA fila %d está vazia", choose);

                } else {
                    printf("\nA fila %d não está vazia", choose);
                }
                break;

            case 3:

                printf("Escolha a fila para verificar se esta cheia (1 ou 2): ");
                scanf("%d", &choose);

                if ((choose == 1 && isFullQueue(queue1) == 1) || (choose == 2 && isFullQueue(queue2) == 1)) {
                    printf("\nFila %d esta cheia", choose);

                } else {

                    printf("\nFila %d nao esta cheia", choose);

                }
                break;

            case 4:

                printf("Escolha a fila para enfileirar (1 ou 2): ");
                scanf("%d", &choose);

                printf("Digite o valor: ");
                scanf("%d", &value);

                if ((choose == 1 && insertQueue(queue1, value) == 1) || (choose == 2 && insertQueue(queue2, value) == 1)) {

                    printf("\nValor %d enfileirado na fila %d", value, choose);

                } else {

                    printf("Erro ao enfileirar");

                }

                break;

            case 5:

                printf("Escolha a fila para desenfileirar (1 ou 2): ");
                scanf("%d", &choose);

                if ((choose == 1 && removeQueue(queue1)) || (choose == 2 && removeQueue(queue2))) {

                    printf("Elemento desenfileirado da fila %d", choose);

                } else {

                    printf("Fila vazia ou erro");

                }
                break;

            case 6:

                printf("Escolha a fila para ler o inicio (1 ou 2): ");
                scanf("%d", &choose);

                int n;
                if (choose == 1 && consultQueue(queue1, &n) == 1) {

                    printf("Inicio da fila 1: %d\n", n);

                } else if (choose == 2 && consultQueue(queue2, &n) == 1) {

                    printf("Inicio da fila 2: %d\n", n);

                } else {

                    printf("Fila %d esta vazia.\n", choose);

                }

                break;

            case 7:

                if (sizeQueue(queue1) > sizeQueue(queue2)) {

                    printf("Fila 1 é maior");

                } else if (sizeQueue(queue1) > sizeQueue(queue2)) {

                    printf("Fila 2 é maior");

                } else {

                    printf("Mesmo tamanho");

                }

                break;

            case 8:

                printf("Escolha a fila (1 ou 2): ");
                scanf("%d", &choose);

                printf("Digite o valor: ");
                scanf("%d", &value);

                if ((choose == 1 && CutInLine(queue1, value) == 1) || (choose == 2 && CutInLine(queue2, value) == 1)) {

                    printf("Valor %d inserido no inicio da fila %d", value, choose);

                } else {

                    printf("Erro");

                }

                break;

            default:
                printf("\n\nOpcao invalida! Tente novamente\n\n");
        }
    }

}