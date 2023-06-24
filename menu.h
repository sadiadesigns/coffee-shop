#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "features.h"

void showMenu();
void addCoffee();
void sellCoffee();
void showInventory();
void removeCoffee();
void showBalance();


void showMenu() {
    int choice;

    do {
        printf("******************    MENU    *******************\n");
        printf("**************************************************\n");
        printf("1. Add Coffee\n");
        printf("2. Sell Coffee\n");
        printf("3. Show Inventory\n");
        printf("4. Show Balance\n");
        printf("5. Remove Coffee\n");
        printf("6. Exit Program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCoffee();
                break;
            case 2:
                sellCoffee();
                break;
            case 3:
                showInventory();
                break;
            case 4:
                showBalance();
                break;
            case 5:
                removeCoffee();
                break;
            case 6:
                exitProgram();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    } while (choice != 6);
}
