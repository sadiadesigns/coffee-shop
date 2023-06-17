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

int main() {
    showSplashScreen();
    showLoginPanel();
    return 0;
}

void showSplashScreen() {
    printf("**************************************************\n");
    printf("********        SADIA'S COFFEE SHOP        *******\n");
    printf("**************************************************\n\n");
    // sleep(2); // Sleep for 4 seconds
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