#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "helper.h"
#include "quote.h"
#include "match.h"
#include "calculator.h"

/* ---------------- Getter functions ---------------- */
int getId(User u) { return u.id; }
char* getEmail(User *u) { return u->email; }
char* getName(User *u) { return u->name; }
char* getGender(User *u) { return u->gender; }
int getAge(User u) { return u.age; }
char* getDistrict(User *u) { return u->district; }
char* getProfession(User *u) { return u->profession; }
char* getEducation(User *u) { return u->education; }
float getHeight(User u) { return u.height; }
int getSalary(User u) { return u.salary; }

/* ---------------- Setter functions ---------------- */
void setPassword(User *u, char password[]) { strcpy(u->password, password); }
void setName(User *u, char name[]) { strcpy(u->name, name); }
void setGender(User *u, char gender[]) { strcpy(u->gender, gender); }
void setAge(User *u, int age) { u->age = age; }
void setReligion(User *u, char religion[]) { strcpy(u->religion, religion); }
void setDistrict(User *u, char district[]) { strcpy(u->district, district); }
void setProfession(User *u, char profession[]) { strcpy(u->profession, profession); }
void setEducation(User *u, char education[]) { strcpy(u->education, education); }
void setHeight(User *u, float height) { u->height = height; }
void setSalary(User *u, int salary) { u->salary = salary; }
void setHobby(User *u, char hobby[]) { strcpy(u->hobby, hobby); }
void setMaritalStatus(User *u, char maritalStatus[]) { strcpy(u->maritalStatus, maritalStatus); }
void setPreferredAge(User *u, int minAge, int maxAge) { u->preferredAgeMin = minAge; u->preferredAgeMax = maxAge; }
void setPreferredDistrict(User *u, char district[]) { strcpy(u->preferredDistrict, district); }
void setPreferredEducation(User *u, char education[]) { strcpy(u->preferredEducation, education); }
void setPreferredProfession(User *u, char profession[]) { strcpy(u->preferredProfession, profession); }

int loadUsers(User users[]) {
    FILE *fp;
    char line[1000];
    char *part;
    int total = 0;

    fp = fopen(USERS_FILE, "r");
    if (fp == NULL) {
        return 0;
    }

    while (fgets(line, 1000, fp) != NULL && total < MAX_USERS) {
        removeNewLine(line);

        part = strtok(line, "|");
        if (part == NULL) continue;
        users[total].active = atoi(part);

        part = strtok(NULL, "|");
        if (part == NULL) continue;
        users[total].id = atoi(part);

        part = strtok(NULL, "|");
        if (part == NULL) continue;
        strcpy(users[total].email, part);

        part = strtok(NULL, "|");
        if (part == NULL) continue;
        strcpy(users[total].password, part);

        part = strtok(NULL, "|");
        if (part == NULL) continue;
        strcpy(users[total].name, part);

        part = strtok(NULL, "|");
        if (part == NULL) continue;
        strcpy(users[total].gender, part);

        part = strtok(NULL, "|");
        if (part == NULL) continue;
        users[total].age = atoi(part);

        part = strtok(NULL, "|");
        if (part == NULL) continue;
        strcpy(users[total].religion, part);

        part = strtok(NULL, "|");
        if (part == NULL) continue;
        strcpy(users[total].district, part);

        part = strtok(NULL, "|");
        if (part == NULL) continue;
        strcpy(users[total].profession, part);

        part = strtok(NULL, "|");
        if (part == NULL) continue;
        strcpy(users[total].education, part);

        part = strtok(NULL, "|");
        if (part == NULL) continue;
        users[total].height = (float)atof(part);

        part = strtok(NULL, "|");
        if (part == NULL) continue;
        users[total].salary = atoi(part);

        part = strtok(NULL, "|");
        if (part == NULL) continue;
        strcpy(users[total].hobby, part);

        part = strtok(NULL, "|");
        if (part == NULL) continue;
        strcpy(users[total].maritalStatus, part);

        part = strtok(NULL, "|");
        if (part == NULL) continue;
        users[total].preferredAgeMin = atoi(part);

        part = strtok(NULL, "|");
        if (part == NULL) continue;
        users[total].preferredAgeMax = atoi(part);

        part = strtok(NULL, "|");
        if (part == NULL) continue;
        strcpy(users[total].preferredDistrict, part);

        part = strtok(NULL, "|");
        if (part == NULL) continue;
        strcpy(users[total].preferredEducation, part);

        part = strtok(NULL, "|");
        if (part == NULL) continue;
        strcpy(users[total].preferredProfession, part);

        total++;
    }

    fclose(fp);
    return total;
}

void saveUsers(User users[], int total) {
    FILE *fp;
    int i;

    fp = fopen(USERS_FILE, "w");
    if (fp == NULL) {
        printf("Could not save users.\n");
        return;
    }

    for (i = 0; i < total; i++) {
        fprintf(fp, "%d|%d|%s|%s|%s|%s|%d|%s|%s|%s|%s|%.2f|%d|%s|%s|%d|%d|%s|%s|%s\n",
            users[i].active,
            users[i].id,
            users[i].email,
            users[i].password,
            users[i].name,
            users[i].gender,
            users[i].age,
            users[i].religion,
            users[i].district,
            users[i].profession,
            users[i].education,
            users[i].height,
            users[i].salary,
            users[i].hobby,
            users[i].maritalStatus,
            users[i].preferredAgeMin,
            users[i].preferredAgeMax,
            users[i].preferredDistrict,
            users[i].preferredEducation,
            users[i].preferredProfession
        );
    }

    fclose(fp);
}

void addUserToFile(User u) {
    FILE *fp;

    fp = fopen(USERS_FILE, "a");
    if (fp == NULL) {
        printf("Could not open users.txt file.\n");
        return;
    }

    fprintf(fp, "%d|%d|%s|%s|%s|%s|%d|%s|%s|%s|%s|%.2f|%d|%s|%s|%d|%d|%s|%s|%s\n",
        u.active,
        u.id,
        u.email,
        u.password,
        u.name,
        u.gender,
        u.age,
        u.religion,
        u.district,
        u.profession,
        u.education,
        u.height,
        u.salary,
        u.hobby,
        u.maritalStatus,
        u.preferredAgeMin,
        u.preferredAgeMax,
        u.preferredDistrict,
        u.preferredEducation,
        u.preferredProfession
    );

    fclose(fp);
}

int findUserByEmail(User users[], int total, char email[]) {
    int i;
    for (i = 0; i < total; i++) {
        if (users[i].active == 1 && strcmp(users[i].email, email) == 0) {
            return i;
        }
    }
    return -1;
}

int findLogin(User users[], int total, char email[], char password[]) {
    int i;
    for (i = 0; i < total; i++) {
        if (users[i].active == 1 && strcmp(users[i].email, email) == 0 && strcmp(users[i].password, password) == 0) {
            return i;
        }
    }
    return -1;
}

int generateUniqueId(User users[], int total) {
    int id, i, found;

    do {
        id = 10000 + rand() % 90000;
        found = 0;
        for (i = 0; i < total; i++) {
            if (users[i].id == id) {
                found = 1;
                break;
            }
        }
    } while (found == 1);

    return id;
}

void registerUser() {
    User users[MAX_USERS];
    User u;
    int total;
    int emailIndex;

    total = loadUsers(users);

    if (total >= MAX_USERS) {
        printf("User limit full. Cupid database is overloaded.\n");
        return;
    }

    printLine();
    printf("NEW USER REGISTRATION\n");
    printLine();

    u.active = 1;
    u.id = generateUniqueId(users, total);
    printf("Your auto generated user ID is: %d\n", u.id);

    showRandomQuote("EMAIL", 0);
    readLine("Enter email: ", u.email, MAX_TEXT);

    emailIndex = findUserByEmail(users, total, u.email);
    if (emailIndex != -1) {
        printf("This email already exists. Try login instead.\n");
        return;
    }

    showRandomQuote("PASSWORD", 0);
    readLine("Create password: ", u.password, MAX_TEXT);

    showRandomQuote("NAME", 0);
    readLine("Enter full name: ", u.name, MAX_TEXT);

    showRandomQuote("GENDER", 0);
    readLine("Enter gender: ", u.gender, MAX_TEXT);

    u.age = getIntInput("Enter age: ");
    showRandomQuote("AGE", u.age);

    showRandomQuote("RELIGION", 0);
    readLine("Enter religion: ", u.religion, MAX_TEXT);

    showRandomQuote("DISTRICT", 0);
    readLine("Enter district: ", u.district, MAX_TEXT);

    showRandomQuote("PROFESSION", 0);
    readLine("Enter profession: ", u.profession, MAX_TEXT);

    showRandomQuote("EDUCATION", 0);
    readLine("Enter education: ", u.education, MAX_TEXT);

    u.height = getFloatInput("Enter height in feet, example 5.8: ");
    showRandomQuote("HEIGHT", (int)(u.height * 10));

    u.salary = getIntInput("Enter monthly salary/income: ");
    showRandomQuote("SALARY", u.salary);

    showRandomQuote("HOBBY", 0);
    readLine("Enter hobby: ", u.hobby, MAX_TEXT);

    showRandomQuote("MARITAL", 0);
    readLine("Enter marital status: ", u.maritalStatus, MAX_TEXT);

    showRandomQuote("PREFAGE", 0);
    u.preferredAgeMin = getIntInput("Preferred minimum age: ");
    u.preferredAgeMax = getIntInput("Preferred maximum age: ");

    showRandomQuote("PREFDISTRICT", 0);
    readLine("Preferred district: ", u.preferredDistrict, MAX_TEXT);

    showRandomQuote("PREFEDUCATION", 0);
    readLine("Preferred education: ", u.preferredEducation, MAX_TEXT);

    showRandomQuote("PREFPROFESSION", 0);
    readLine("Preferred profession: ", u.preferredProfession, MAX_TEXT);

    addUserToFile(u);

    showRandomQuote("REGISTER_DONE", 0);
    printf("Your profile has been saved successfully.\n");
}

void viewProfile(User u) {
    printLine();
    printf("PROFILE OF %s\n", u.name);
    printLine();
    printf("User ID              : %d\n", u.id);
    printf("Email                : %s\n", u.email);
    printf("Name                 : %s\n", u.name);
    printf("Gender               : %s\n", u.gender);
    printf("Age                  : %d\n", u.age);
    printf("Religion             : %s\n", u.religion);
    printf("District             : %s\n", u.district);
    printf("Profession           : %s\n", u.profession);
    printf("Education            : %s\n", u.education);
    printf("Height               : %.2f\n", u.height);
    printf("Salary               : %d\n", u.salary);
    printf("Hobby                : %s\n", u.hobby);
    printf("Marital Status       : %s\n", u.maritalStatus);
    printf("Preferred Age        : %d to %d\n", u.preferredAgeMin, u.preferredAgeMax);
    printf("Preferred District   : %s\n", u.preferredDistrict);
    printf("Preferred Education  : %s\n", u.preferredEducation);
    printf("Preferred Profession : %s\n", u.preferredProfession);
    printLine();
}

void editProfile(User users[], int total, int index) {
    int choice;
    char text[MAX_TEXT];
    int n1, n2;
    float f;

    do {
        printLine();
        printf("EDIT PROFILE MENU\n");
        printLine();
        printf("1. Change password\n");
        printf("2. Change name\n");
        printf("3. Change gender\n");
        printf("4. Change age\n");
        printf("5. Change religion\n");
        printf("6. Change district\n");
        printf("7. Change profession\n");
        printf("8. Change education\n");
        printf("9. Change height\n");
        printf("10. Change salary\n");
        printf("11. Change hobby\n");
        printf("12. Change marital status\n");
        printf("13. Change preferred age range\n");
        printf("14. Change preferred district\n");
        printf("15. Change preferred education\n");
        printf("16. Change preferred profession\n");
        printf("0. Back\n");

        choice = getIntInput("Choose option: ");

        switch (choice) {
            case 1:
                readLine("New password: ", text, MAX_TEXT);
                setPassword(&users[index], text);
                break;
            case 2:
                readLine("New name: ", text, MAX_TEXT);
                setName(&users[index], text);
                break;
            case 3:
                readLine("New gender: ", text, MAX_TEXT);
                setGender(&users[index], text);
                break;
            case 4:
                n1 = getIntInput("New age: ");
                setAge(&users[index], n1);
                showRandomQuote("AGE", n1);
                break;
            case 5:
                readLine("New religion: ", text, MAX_TEXT);
                setReligion(&users[index], text);
                break;
            case 6:
                readLine("New district: ", text, MAX_TEXT);
                setDistrict(&users[index], text);
                break;
            case 7:
                readLine("New profession: ", text, MAX_TEXT);
                setProfession(&users[index], text);
                break;
            case 8:
                readLine("New education: ", text, MAX_TEXT);
                setEducation(&users[index], text);
                break;
            case 9:
                f = getFloatInput("New height: ");
                setHeight(&users[index], f);
                showRandomQuote("HEIGHT", (int)(f * 10));
                break;
            case 10:
                n1 = getIntInput("New salary: ");
                setSalary(&users[index], n1);
                showRandomQuote("SALARY", n1);
                break;
            case 11:
                readLine("New hobby: ", text, MAX_TEXT);
                setHobby(&users[index], text);
                break;
            case 12:
                readLine("New marital status: ", text, MAX_TEXT);
                setMaritalStatus(&users[index], text);
                break;
            case 13:
                n1 = getIntInput("Preferred minimum age: ");
                n2 = getIntInput("Preferred maximum age: ");
                setPreferredAge(&users[index], n1, n2);
                break;
            case 14:
                readLine("New preferred district: ", text, MAX_TEXT);
                setPreferredDistrict(&users[index], text);
                break;
            case 15:
                readLine("New preferred education: ", text, MAX_TEXT);
                setPreferredEducation(&users[index], text);
                break;
            case 16:
                readLine("New preferred profession: ", text, MAX_TEXT);
                setPreferredProfession(&users[index], text);
                break;
            case 0:
                break;
            default:
                printf("Invalid option.\n");
        }

        if (choice >= 1 && choice <= 16) {
            saveUsers(users, total);
            printf("Profile updated successfully. Database accepted your new personality.\n");
        }

    } while (choice != 0);
}

void deleteOwnProfile(User users[], int total, int index) {
    char confirm[MAX_TEXT];

    readLine("Type YES to delete/deactivate your profile: ", confirm, MAX_TEXT);
    if (strcmp(confirm, "YES") == 0) {
        users[index].active = 0;
        saveUsers(users, total);
        printf("Your profile is deactivated. Cupid will miss you.\n");
    } else {
        printf("Delete cancelled. Love database saved from heartbreak.\n");
    }
}

void userMenu(User users[], int total, int index) {
    int choice;

    do {
        printLine();
        printf("USER MENU - Welcome %s\n", users[index].name);
        printLine();
        printf("1. View my profile\n");
        printf("2. Edit my profile\n");
        printf("3. Suggested matches\n");
        printf("4. Love calculator\n");
        printf("5. Marriage cost calculator\n");
        printf("6. Delete/deactivate my profile\n");
        printf("0. Logout\n");

        choice = getIntInput("Choose option: ");

        switch (choice) {
            case 1:
                viewProfile(users[index]);
                pauseScreen();
                break;
            case 2:
                editProfile(users, total, index);
                break;
            case 3:
                showSuggestedMatches(users, total, index);
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
                deleteOwnProfile(users, total, index);
                choice = 0;
                pauseScreen();
                break;
            case 0:
                printf("Logged out. May your next login be more romantic.\n");
                break;
            default:
                printf("Invalid option.\n");
        }

    } while (choice != 0);
}
