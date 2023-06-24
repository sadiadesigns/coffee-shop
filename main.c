#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "login.h"
#include "menu.h"
#include "splash.h"

int main() {
    showSplashScreen();
    showLoginPanel();
    showMenu();
    return 0;
}