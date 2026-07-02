#include <stdio.h>
#include <string.h>
#include "match.h"
#include "helper.h"
#include "quote.h"

int sameText(char a[], char b[]) {
    if (strcmp(a, b) == 0) {
        return 1;
    }
    return 0;
}

int calculateMatchScore(User current, User candidate) {
    int score = 0;

    /* Candidate age matches current user's preference */
    if (candidate.age >= current.preferredAgeMin && candidate.age <= current.preferredAgeMax) {
        score += 25;
    }

    /* Current user's age matches candidate's preference */
    if (current.age >= candidate.preferredAgeMin && current.age <= candidate.preferredAgeMax) {
        score += 15;
    }

    if (sameText(candidate.district, current.preferredDistrict)) {
        score += 15;
    }

    if (sameText(candidate.education, current.preferredEducation)) {
        score += 15;
    }

    if (sameText(candidate.profession, current.preferredProfession)) {
        score += 15;
    }

    if (sameText(candidate.religion, current.religion)) {
        score += 10;
    }

    if (sameText(candidate.maritalStatus, current.maritalStatus)) {
        score += 3;
    }

    if (sameText(candidate.hobby, current.hobby)) {
        score += 2;
    }

    if (score > 100) {
        score = 100;
    }

    return score;
}

void sortMatches(MatchResult matches[], int total) {
    int i, j;
    MatchResult temp;

    for (i = 0; i < total - 1; i++) {
        for (j = 0; j < total - i - 1; j++) {
            if (matches[j].score < matches[j + 1].score) {
                temp = matches[j];
                matches[j] = matches[j + 1];
                matches[j + 1] = temp;
            }
        }
    }
}

void showSuggestedMatches(User users[], int total, int currentIndex) {
    MatchResult matches[MAX_USERS];
    int matchTotal = 0;
    int i, score;
    int candidateIndex;

    for (i = 0; i < total; i++) {
        if (i != currentIndex && users[i].active == 1) {
            score = calculateMatchScore(users[currentIndex], users[i]);
            matches[matchTotal].userIndex = i;
            matches[matchTotal].score = score;
            matchTotal++;
        }
    }

    if (matchTotal == 0) {
        printf("No other users found. Cupid is alone in the server room.\n");
        return;
    }

    sortMatches(matches, matchTotal);

    printLine();
    printf("SUGGESTED MATCHES FOR %s\n", users[currentIndex].name);
    printLine();
    printf("Sorted from best match to lowest match.\n\n");

    for (i = 0; i < matchTotal; i++) {
        candidateIndex = matches[i].userIndex;

        printf("%d. %s | Age: %d | District: %s | Education: %s | Profession: %s | Score: %d%%\n",
            i + 1,
            users[candidateIndex].name,
            users[candidateIndex].age,
            users[candidateIndex].district,
            users[candidateIndex].education,
            users[candidateIndex].profession,
            matches[i].score
        );

        if (matches[i].score >= 75) {
            showRandomQuote("MATCH_HIGH", 0);
        } else if (matches[i].score >= 40) {
            showRandomQuote("MATCH_MID", 0);
        } else {
            showRandomQuote("MATCH_LOW", 0);
        }
        printf("\n");
    }
}
