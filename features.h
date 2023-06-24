#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"

#define MAX_COFFEE_NAME_LENGTH 50
#define MAX_FILENAME_LENGTH 100

// Function to add a new coffee to the inventory
void addCoffee() {
    char coffeeName[MAX_COFFEE_NAME_LENGTH];
    float price;
    int quantity;

    printf("**************    ADD COFFEE    *****************\n");
    printf("**************************************************\n");
    printf("Enter the name of the coffee: ");
    scanf("%s", coffeeName);
    printf("Enter the price of the coffee: ");
    scanf("%f", &price);
    printf("Enter the quantity of the coffee: ");
    scanf("%d", &quantity);

    // Open the database file for reading
    FILE* file = fopen("database.txt", "r");
    if (file == NULL) {
        createDatabaseFile(); // Create the database file if it doesn't exist
        file = fopen("database.txt", "r");
        if (file == NULL) {
            printf("Error opening the file.\n");
            return;
        }
    }

    // Determine the ID for the new coffee entry
    int id = 0;
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        id++;
    }

    fclose(file);

    // Open the database file in append mode to add the new coffee entry
    file = fopen("database.txt", "a");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    // Write the new coffee entry to the database file
    fprintf(file, "%d,%s,%.2f,%d\n", id + 1, coffeeName, price, quantity);
    fclose(file);

    printf("Coffee added successfully!\n");
}

// Function to sell a coffee from the inventory
void sellCoffee() {
    printf("**************    SELL COFFEE   *****************\n");
    printf("**************************************************\n");

    int id;
    int quantity;

    printf("Enter the ID of the coffee to sell: ");
    scanf("%d", &id);
    printf("Enter the quantity to sell: ");
    scanf("%d", &quantity);

    // Open the database file for reading and writing
    FILE* file = fopen("database.txt", "r+");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    char line[100];
    int found = 0;
    int updatedQuantity = 0;
    long int currentPosition = 0;

    // Iterate through each line in the file to find the coffee with the given ID
    while (fgets(line, sizeof(line), file)) {
        int coffeeId;
        char coffeeName[MAX_COFFEE_NAME_LENGTH];
        float price;
        int stockQuantity;

        sscanf(line, "%d,%[^,],%f,%d", &coffeeId, coffeeName, &price, &stockQuantity);

        if (coffeeId == id) {
            found = 1;

            if (quantity <= stockQuantity) {
                updatedQuantity = stockQuantity - quantity;
                fseek(file, currentPosition, SEEK_SET);
                fprintf(file, "%d,%s,%.2f,%d\n", coffeeId, coffeeName, price, updatedQuantity);
                printf("Coffee sold successfully!\n");

                // Update the balance file with the total sales
                FILE* balanceFile = fopen("balance.txt", "a");
                if (balanceFile == NULL) {
                    printf("Error opening the balance file.\n");
                    fclose(file);
                    return;
                }

                float totalAmount = price * quantity;
                fprintf(balanceFile, "%.2f\n", totalAmount);
                fclose(balanceFile);
            } else {
                printf("Insufficient quantity in stock.\n");
            }
            break;
        }

        currentPosition = ftell(file);
    }

    if (!found) {
        printf("Coffee not found in stock.\n");
    }

    fclose(file);
}

// Function to display the inventory
void showInventory() {
    printf("**************    INVENTORY    ******************\n");
    printf("**************************************************\n");
    printf("ID\tCoffee Name\tPrice\tQuantity\n");
    printf("===============================================\n");

    // Open the database file for reading
    FILE* file = fopen("database.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        int coffeeId;
        char coffeeName[MAX_COFFEE_NAME_LENGTH];
        float price;
        int quantity;

        sscanf(line, "%d,%[^,],%f,%d", &coffeeId, coffeeName, &price, &quantity);
        printf("%d\t%s\t\t%.2f\t%d\n", coffeeId, coffeeName, price, quantity);
    }

    fclose(file);
}

// Function to display the total sales balance
void showBalance() {
    printf("****************    BALANCE    ******************\n");
    printf("**************************************************\n");

    // Open the balance file for reading
    FILE* balanceFile = fopen("balance.txt", "r");
    if (balanceFile == NULL) {
        printf("Error opening the balance file.\n");
        return;
    }

    float totalSales = 0.0;
    char line[100];
    while (fgets(line, sizeof(line), balanceFile)) {
        float amount = atof(line);
        totalSales += amount;
    }

    fclose(balanceFile);

    printf("Total Sales: %.2f\n", totalSales);
}

// Function to remove a coffee from the inventory
void removeCoffee() {
    printf("*************    REMOVE COFFEE    ****************\n");
    printf("**************************************************\n");

    int id;
    printf("Enter the ID of the coffee to remove: ");
    scanf("%d", &id);

    // Open the database file for reading and writing
    FILE* file = fopen("database.txt", "r+");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    // Create a temporary file for rewriting the database without the removed coffee
    FILE* tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error creating temporary file.\n");
        fclose(file);
        return;
    }

    char line[100];
    int found = 0;

    // Iterate through each line in the file and copy lines to the temporary file except for the one with the given ID
    while (fgets(line, sizeof(line), file)) {
        int coffeeId;
        char coffeeName[MAX_COFFEE_NAME_LENGTH];
        float price;
        int quantity;

        sscanf(line, "%d,%[^,],%f,%d", &coffeeId, coffeeName, &price, &quantity);

        if (coffeeId != id) {
            fprintf(tempFile, "%d,%s,%.2f,%d\n", coffeeId, coffeeName, price, quantity);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    // Replace the original database file with the temporary file if the coffee was found and removed
    if (found) {
        remove("database.txt");
        rename("temp.txt", "database.txt");
        printf("Coffee removed successfully!\n");
    } else {
        remove("temp.txt");
        printf("Coffee not found.\n");
    }
}
