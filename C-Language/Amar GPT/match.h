#ifndef MATCH_H
#define MATCH_H

#include "user.h"

typedef struct {
    int userIndex;
    int score;
} MatchResult;

int sameText(char a[], char b[]);
int calculateMatchScore(User current, User candidate);
void sortMatches(MatchResult matches[], int total);
void showSuggestedMatches(User users[], int total, int currentIndex);

#endif
