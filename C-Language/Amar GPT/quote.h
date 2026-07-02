#ifndef QUOTE_H
#define QUOTE_H

void ensureQuoteFile();
int getRandomQuote(char category[], int value, char output[]);
void showRandomQuote(char category[], int value);
void createDefaultQuoteFile();

#endif
