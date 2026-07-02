#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "user.h"
#include "admin.h"
#include "calculator.h"
#include "helper.h"
#include "quote.h"

void mainMenu();
void loginUser();
void aboutProject();

int main() {
    srand(time(0));
    ensureQuoteFile();
    mainMenu();
    return 0;
}

void mainMenu() {
    int choice;

    do {
        printLine();
        printf("FUNNY MATRIMONY CONSOLE APP\n");
        printf("Where C Programming Meets Confused Cupid\n");
        printLine();
        printf("1. Register new user\n");
        printf("2. User login\n");
        printf("3. Admin login\n");
        printf("4. Love calculator\n");
        printf("5. Marriage cost calculator\n");
        printf("6. About project\n");
        printf("0. Exit\n");

        choice = getIntInput("Choose option: ");

        switch (choice) {
            case 1:
                registerUser();
                pauseScreen();
                break;
            case 2:
                loginUser();
                pauseScreen();
                break;
            case 3:
                adminLogin();
                pauseScreen();
                break;
            case 4:
                loveCalculator();
                pauseScreen();
                break;
            case 5:
                marriageCostCalculator();
                pauseScreen();
                break;
            case 6:
                aboutProject();
                pauseScreen();
                break;
            case 0:
                printf("Goodbye. May your code compile and your love life not segfault.\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }

    } while (choice != 0);
}

void loginUser() {
    User users[MAX_USERS];
    int total;
    int index;
    char email[MAX_TEXT];
    char password[MAX_TEXT];

    total = loadUsers(users);

    printLine();
    printf("USER LOGIN\n");
    printLine();

    readLine("Enter email: ", email, MAX_TEXT);
    readLine("Enter password: ", password, MAX_TEXT);

    index = findLogin(users, total, email, password);

    if (index == -1) {
        showRandomQuote("LOGIN_FAIL", 0);
    } else {
        showRandomQuote("LOGIN_SUCCESS", 0);
        userMenu(users, total, index);
    }
}

void aboutProject() {
    printLine();
    printf("ABOUT THIS PROJECT\n");
    printLine();
    printf("Project name : Funny Matrimony Console App\n");
    printf("Language     : C\n");
    printf("Data files   : users.txt and Quote.txt\n");
    printf("Main topics  : variable, condition, loop, switch, array, pointer,\n");
    printf("               function, struct, header file, text file, random number,\n");
    printf("               getter and setter.\n\n");
    printf("Features:\n");
    printf("- Register user with funny quotes\n");
    printf("- Login using email and password\n");
    printf("- View and edit personal profile\n");
    printf("- Save and update data in users.txt\n");
    printf("- Suggested matches sorted by matching score\n");
    printf("- Love calculator\n");
    printf("- Marriage cost calculator\n");
    printf("- Admin panel\n\n");
    printf("Admin login: username = admin, password = admin123\n");
}
