#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_COFFEE_NAME_LENGTH 50
#define MAX_FILENAME_LENGTH 100

void showSplashScreen();
void showLoginPanel();
int authenticateUser(char* username, char* password);
void showMenu();
void addCoffee();
void removeCoffee();
void exitProgram();

void createDatabaseFile();

int main() {
    showSplashScreen();
    showLoginPanel();
    showMenu();
    return 0;
}


void delay(int seconds) {
    time_t start_time = time(NULL);
    while (time(NULL) - start_time < seconds)
        ; // Loop until the specified number of seconds has passed
}

void showSplashScreen() {
    printf("**************************************************\n");
    printf("********        SADIA'S COFFEE SHOP        *******\n");
    printf("**************************************************\n\n");
    delay(2);
    system("clear"); // Clear the screen
}

void showLoginPanel() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("************      LOGIN PANEL       **************\n");
    printf("**************************************************\n");
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    if (authenticateUser(username, password)) {
        printf("Login successful!\n\n");
    } else {
        printf("Invalid username or password. Exiting program.\n");
        exit(0);
    }
}

int authenticateUser(char* username, char* password) {
    if (strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0) {
        return 1;
    }
    return 0;
}

void showMenu() {
    int choice;

    do {
        printf("******************    MENU    *******************\n");
        printf("**************************************************\n");
        printf("1. Add Coffee\n");
        printf("2. Remove Coffee\n");
        printf("3. Exit Program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCoffee();
                break;
            case 2:
                removeCoffee();
                break;
            case 3:
                exitProgram();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    } while (choice != 3);
}

void createDatabaseFile() {
    FILE* file = fopen("database.txt", "a");
    if (file == NULL) {
        printf("Error creating the file.\n");
        exit(1);
    }
    fclose(file);
}

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

    FILE* file = fopen("database.txt", "r");
    if (file == NULL) {
        createDatabaseFile();
        file = fopen("database.txt", "r");
        if (file == NULL) {
            printf("Error opening the file.\n");
            return;
        }
    }

    int id = 0;
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        id++;
    }

    fclose(file);

    file = fopen("database.txt", "a");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    fprintf(file, "%d,%s,%.2f,%d\n", id + 1, coffeeName, price, quantity);
    fclose(file);

    printf("Coffee added successfully!\n");
}

void removeCoffee() {
    printf("*************    REMOVE COFFEE    ****************\n");
    printf("**************************************************\n");

    int id;
    printf("Enter the ID of the coffee to remove: ");
    scanf("%d", &id);

    FILE* file = fopen("database.txt", "r+");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    FILE* tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error creating temporary file.\n");
        fclose(file);
        return;
    }

    char line[100];
    int found = 0;

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

    if (found) {
        remove("database.txt");
        rename("temp.txt", "database.txt");
        printf("Coffee removed successfully!\n");
    } else {
        remove("temp.txt");
        printf("Coffee not found.\n");
    }
}


void exitProgram() {
    printf("Exiting program...\n");
    exit(0);
}