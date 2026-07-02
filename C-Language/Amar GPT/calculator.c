#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "calculator.h"
#include "helper.h"
#include "quote.h"
#include "app_config.h"

void loveCalculator() {
    char name1[MAX_TEXT], name2[MAX_TEXT];
    int i, total = 0, score;

    printLine();
    printf("LOVE CALCULATOR\n");
    printLine();

    readLine("Enter first name: ", name1, MAX_TEXT);
    readLine("Enter second name: ", name2, MAX_TEXT);

    for (i = 0; name1[i] != '\0'; i++) {
        total += name1[i];
    }

    for (i = 0; name2[i] != '\0'; i++) {
        total += name2[i];
    }

    score = (total + rand() % 31) % 101;

    printf("\nLove score between %s and %s is: %d%%\n", name1, name2, score);

    if (score >= 75) {
        showRandomQuote("LOVE_HIGH", 0);
    } else if (score >= 40) {
        showRandomQuote("LOVE_MID", 0);
    } else {
        showRandomQuote("LOVE_LOW", 0);
    }
}

void marriageCostCalculator() {
    int guests;
    int foodPerPerson;
    int hallCost;
    int decorationCost;
    int dressCost;
    int photographyCost;
    int extraCost;
    int total;

    printLine();
    printf("MARRIAGE COST CALCULATOR\n");
    printLine();

    guests = getIntInput("Number of guests: ");
    foodPerPerson = getIntInput("Food cost per person: ");
    hallCost = getIntInput("Hall/venue cost: ");
    decorationCost = getIntInput("Decoration cost: ");
    dressCost = getIntInput("Dress/shopping cost: ");
    photographyCost = getIntInput("Photography cost: ");
    extraCost = getIntInput("Extra emergency cost: ");

    total = (guests * foodPerPerson) + hallCost + decorationCost + dressCost + photographyCost + extraCost;

    printf("\nEstimated marriage cost: %d\n", total);

    if (total < 100000) {
        showRandomQuote("COST_LOW", 0);
    } else if (total <= 500000) {
        showRandomQuote("COST_MID", 0);
    } else {
        showRandomQuote("COST_HIGH", 0);
    }
}
