#ifndef USER_H
#define USER_H

#include "app_config.h"

typedef struct {
    int active;
    int id;
    char email[MAX_TEXT];
    char password[MAX_TEXT];
    char name[MAX_TEXT];
    char gender[MAX_TEXT];
    int age;
    char religion[MAX_TEXT];
    char district[MAX_TEXT];
    char profession[MAX_TEXT];
    char education[MAX_TEXT];
    float height;
    int salary;
    char hobby[MAX_TEXT];
    char maritalStatus[MAX_TEXT];
    int preferredAgeMin;
    int preferredAgeMax;
    char preferredDistrict[MAX_TEXT];
    char preferredEducation[MAX_TEXT];
    char preferredProfession[MAX_TEXT];
} User;

/* Getter functions */
int getId(User u);
char* getEmail(User *u);
char* getName(User *u);
char* getGender(User *u);
int getAge(User u);
char* getDistrict(User *u);
char* getProfession(User *u);
char* getEducation(User *u);
float getHeight(User u);
int getSalary(User u);

/* Setter functions */
void setPassword(User *u, char password[]);
void setName(User *u, char name[]);
void setGender(User *u, char gender[]);
void setAge(User *u, int age);
void setReligion(User *u, char religion[]);
void setDistrict(User *u, char district[]);
void setProfession(User *u, char profession[]);
void setEducation(User *u, char education[]);
void setHeight(User *u, float height);
void setSalary(User *u, int salary);
void setHobby(User *u, char hobby[]);
void setMaritalStatus(User *u, char maritalStatus[]);
void setPreferredAge(User *u, int minAge, int maxAge);
void setPreferredDistrict(User *u, char district[]);
void setPreferredEducation(User *u, char education[]);
void setPreferredProfession(User *u, char profession[]);

int loadUsers(User users[]);
void saveUsers(User users[], int total);
void addUserToFile(User u);
int findUserByEmail(User users[], int total, char email[]);
int findLogin(User users[], int total, char email[], char password[]);
int generateUniqueId(User users[], int total);
void registerUser();
void viewProfile(User u);
void editProfile(User users[], int total, int index);
void userMenu(User users[], int total, int index);
void deleteOwnProfile(User users[], int total, int index);

#endif
