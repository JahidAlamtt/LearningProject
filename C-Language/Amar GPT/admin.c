#include <stdio.h>
#include <string.h>
#include "admin.h"
#include "user.h"
#include "helper.h"
#include "quote.h"

void adminLogin() {
    char username[MAX_TEXT];
    char password[MAX_TEXT];

    printLine();
    printf("ADMIN LOGIN\n");
    printLine();

    readLine("Admin username: ", username, MAX_TEXT);
    readLine("Admin password: ", password, MAX_TEXT);

    if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0) {
        showRandomQuote("ADMIN", 0);
        adminMenu();
    } else {
        printf("Wrong admin login. Database romance is protected.\n");
    }
}

void adminMenu() {
    int choice;

    do {
        printLine();
        printf("ADMIN MENU\n");
        printLine();
        printf("1. View all users\n");
        printf("2. Search user by email\n");
        printf("3. Deactivate user\n");
        printf("4. Show statistics\n");
        printf("0. Logout admin\n");

        choice = getIntInput("Choose option: ");

        switch (choice) {
            case 1:
                adminViewAllUsers();
                pauseScreen();
                break;
            case 2:
                adminSearchUser();
                pauseScreen();
                break;
            case 3:
                adminDeactivateUser();
                pauseScreen();
                break;
            case 4:
                adminStatistics();
                pauseScreen();
                break;
            case 0:
                printf("Admin logged out.\n");
                break;
            default:
                printf("Invalid option.\n");
        }

    } while (choice != 0);
}

void adminViewAllUsers() {
    User users[MAX_USERS];
    int total, i;

    total = loadUsers(users);

    printLine();
    printf("ALL ACTIVE USERS\n");
    printLine();

    if (total == 0) {
        printf("No users found. Matrimony market is empty.\n");
        return;
    }

    for (i = 0; i < total; i++) {
        if (users[i].active == 1) {
            printf("ID: %d | Email: %s | Name: %s | Age: %d | District: %s | Profession: %s\n",
                users[i].id,
                users[i].email,
                users[i].name,
                users[i].age,
                users[i].district,
                users[i].profession
            );
        }
    }
}

void adminSearchUser() {
    User users[MAX_USERS];
    int total, index;
    char email[MAX_TEXT];

    total = loadUsers(users);
    readLine("Enter email to search: ", email, MAX_TEXT);

    index = findUserByEmail(users, total, email);

    if (index == -1) {
        printf("User not found. Maybe love escaped.\n");
    } else {
        viewProfile(users[index]);
    }
}

void adminDeactivateUser() {
    User users[MAX_USERS];
    int total, index;
    char email[MAX_TEXT];
    char confirm[MAX_TEXT];

    total = loadUsers(users);
    readLine("Enter user email to deactivate: ", email, MAX_TEXT);

    index = findUserByEmail(users, total, email);

    if (index == -1) {
        printf("User not found.\n");
        return;
    }

    printf("User found: %s\n", users[index].name);
    readLine("Type YES to deactivate: ", confirm, MAX_TEXT);

    if (strcmp(confirm, "YES") == 0) {
        users[index].active = 0;
        saveUsers(users, total);
        printf("User deactivated successfully.\n");
    } else {
        printf("Deactivation cancelled.\n");
    }
}

void adminStatistics() {
    User users[MAX_USERS];
    int total, i;
    int activeCount = 0;
    int inactiveCount = 0;
    int totalAge = 0;
    int averageAge = 0;

    total = loadUsers(users);

    for (i = 0; i < total; i++) {
        if (users[i].active == 1) {
            activeCount++;
            totalAge += users[i].age;
        } else {
            inactiveCount++;
        }
    }

    if (activeCount > 0) {
        averageAge = totalAge / activeCount;
    }

    printLine();
    printf("APP STATISTICS\n");
    printLine();
    printf("Total saved profiles   : %d\n", total);
    printf("Active profiles        : %d\n", activeCount);
    printf("Inactive profiles      : %d\n", inactiveCount);
    printf("Average active age     : %d\n", averageAge);
}
