#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

// Function to authenticate a user based on provided username and password
int authenticateUser(char* username, char* password);

// Function to display the login panel and handle user authentication
void showLoginPanel();

// Implementation of the showLoginPanel function
void showLoginPanel() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int attempts = 0;
    int maxAttempts = 3;

    printf("************      LOGIN PANEL       **************\n");
    printf("**************************************************\n");

    while (attempts < maxAttempts) {
        printf("Enter your username: ");
        scanf("%s", username);
        printf("Enter your password: ");
        scanf("%s", password);

        if (authenticateUser(username, password)) {
            printf("Login successful!\n\n");
            return; // Exit the function when login is successful
        } else {
            printf("Invalid username or password. Please try again.\n");
            attempts++;
        }
    }

    printf("Maximum number of login attempts reached. Exiting program.\n");
    exit(0);
}

// Implementation of the authenticateUser function
int authenticateUser(char* username, char* password) {
    if (strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0) {
        return 1; // Return 1 if the provided username and password match the admin credentials
    }
    return 0; // Return 0 if the authentication fails
}
