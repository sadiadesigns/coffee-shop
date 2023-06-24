#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void exitProgram();
void createDatabaseFile();

void createDatabaseFile() {
    FILE* file = fopen("database.txt", "a");
    if (file == NULL) {
        printf("Error creating the file.\n");
        exit(1);
    }
    fclose(file);
}

void exitProgram() {
    printf("Exiting program...\n");
    exit(0);
}