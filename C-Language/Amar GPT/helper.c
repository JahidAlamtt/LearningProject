#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "helper.h"

void removeNewLine(char text[]) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] == '\n') {
            text[i] = '\0';
            break;
        }
    }
}

void replacePipeSymbol(char text[]) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] == '|') {
            text[i] = '/';
        }
    }
}

void readLine(char message[], char text[], int size) {
    printf("%s", message);
    fgets(text, size, stdin);
    removeNewLine(text);
    replacePipeSymbol(text);
}

int getIntInput(char message[]) {
    char temp[50];
    printf("%s", message);
    fgets(temp, 50, stdin);
    return atoi(temp);
}

float getFloatInput(char message[]) {
    char temp[50];
    printf("%s", message);
    fgets(temp, 50, stdin);
    return (float)atof(temp);
}

void pauseScreen() {
    char temp[10];
    printf("\nPress Enter to continue...");
    fgets(temp, 10, stdin);
}

void printLine() {
    printf("------------------------------------------------------------\n");
}
