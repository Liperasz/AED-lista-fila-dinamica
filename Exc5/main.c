//
// Created by liperasz on 27/04/25.
//
#include "Exc5.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    Queue *tq = createQueue();
    Queue *wq = createQueue();

    while (1) {

        switch(menu()) {

            case 0:

                printf("\nExiting program...\n");
                destroyQueue(tq);
                destroyQueue(wq);
                return 0;

            case 1:
                printf("\nNumber of airplanes in takeoff queue: %d\n", sizeQueue(tq));
                break;

            case 2:

                printf("\nNumber of airplanes in waiting queue: %d\n", sizeQueue(wq));
                break;

            case 3:

                AuthorizeTakeoff(tq);
                break;

            case 4: {

                Airplane plane;

                printf("\nEnter airplane ID: ");
                scanf("%d", &plane.ID);

                printf("Enter airplane model: ");
                scanf(" %[^\n]", plane.model);

                printf("Enter airplane capacity: ");
                scanf("%d", &plane.capacity);

                AddAirplane(tq, plane, 1);

                break;
            }

            case 5: {

                Airplane plane;
                printf("\nEnter airplane ID: ");
                scanf("%d", &plane.ID);

                printf("Enter airplane model: ");
                scanf(" %[^\n]", plane.model);

                printf("Enter airplane capacity: ");
                scanf("%d", &plane.capacity);

                AddAirplane(wq, plane, 2);

                break;
            }

            case 6:

                AirplaneList(tq, 1);
                break;

            case 7:

                AirplaneList(wq, 2);
                break;

            case 8:

                VerifyAirplane(tq, 1);
                break;

            case 9:

                VerifyAirplane(wq, 2);
                break;

            case 10: {

                MoveAirplane(wq, tq);
                break;
            }

            default:


                printf("\nInvalid option! Please try again.\n");
        }

    }
}