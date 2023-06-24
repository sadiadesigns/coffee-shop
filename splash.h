#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void showSplashScreen();
void delay(int seconds);

void showSplashScreen() {
    printf("**************************************************\n");
    printf("********        SADIA'S COFFEE SHOP        *******\n");
    printf("**************************************************\n\n");
    delay(4);
    system("clear"); // Clear the screen
}

void delay(int seconds) {
    time_t start_time = time(NULL);
    while (time(NULL) - start_time < seconds)
        ; // Loop until the specified number of seconds has passed
}
