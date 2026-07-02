#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "app_config.h"
#include "quote.h"
#include "helper.h"

void createDefaultQuoteFile() {
    FILE *fp = fopen(QUOTES_FILE, "w");
    if (fp == NULL) {
        printf("Could not create Quote.txt file.\n");
        return;
    }

    /* Format: CATEGORY|MIN|MAX|QUOTE */
    fprintf(fp, "AGE|0|17|Bro, focus on school first. Love can wait outside the classroom.\n");
    fprintf(fp, "AGE|0|17|Under 18 detected. Matrimony mode changed to homework mode.\n");
    fprintf(fp, "AGE|18|24|Young heart, big dreams, and maybe one confused crush.\n");
    fprintf(fp, "AGE|18|24|Perfect age for dreams, degrees, and dramatic love songs.\n");
    fprintf(fp, "AGE|25|35|Serious marriage age unlocked. Family group chat is watching.\n");
    fprintf(fp, "AGE|25|35|Your relatives have probably started asking suspicious questions.\n");
    fprintf(fp, "AGE|36|60|Mature heart detected. Premium understanding mode activated.\n");
    fprintf(fp, "AGE|61|120|Legendary love level unlocked. Respect!\n");

    fprintf(fp, "EMAIL|0|0|Enter email carefully. Future love letters may depend on it.\n");
    fprintf(fp, "EMAIL|0|0|Use a real email. Pigeon delivery is not supported yet.\n");
    fprintf(fp, "PASSWORD|0|0|Make a password strong enough to protect your secret crush list.\n");
    fprintf(fp, "PASSWORD|0|0|Password please. Do not use your crush name, too risky.\n");
    fprintf(fp, "NAME|0|0|Enter your name. This is the name destiny will print on the wedding card.\n");
    fprintf(fp, "NAME|0|0|Your name please. Nicknames like King of Hearts are optional.\n");
    fprintf(fp, "GENDER|0|0|Enter gender. The algorithm is wearing glasses and trying to understand.\n");
    fprintf(fp, "GENDER|0|0|Gender please. Cupid needs correct direction.\n");
    fprintf(fp, "RELIGION|0|0|Religion helps matching family expectations and dinner table peace.\n");
    fprintf(fp, "DISTRICT|0|0|District please. Distance matters when biryani delivery is involved.\n");
    fprintf(fp, "DISTRICT|0|0|Enter district. Local matches may reduce transport cost.\n");
    fprintf(fp, "PROFESSION|0|0|Profession please. Future in-laws are taking notes.\n");
    fprintf(fp, "PROFESSION|0|0|What do you do? Besides overthinking life, of course.\n");
    fprintf(fp, "EDUCATION|0|0|Education please. Degree is not love, but aunties respect it.\n");
    fprintf(fp, "EDUCATION|0|0|Enter education. The biodata committee is ready.\n");
    fprintf(fp, "HEIGHT|0|50|Height seems tiny. Are you entering centimeters by mistake?\n");
    fprintf(fp, "HEIGHT|51|58|Cute height detected. Confidence adds extra inches.\n");
    fprintf(fp, "HEIGHT|59|66|Nice height. Suitable for both selfies and serious meetings.\n");
    fprintf(fp, "HEIGHT|67|84|Tall personality detected. Ceiling fan should be careful.\n");
    fprintf(fp, "SALARY|0|9999|Salary low, but dreams can still be billionaire level.\n");
    fprintf(fp, "SALARY|10000|29999|Budget-friendly romantic hero detected.\n");
    fprintf(fp, "SALARY|30000|79999|Stable income. Parents may start smiling.\n");
    fprintf(fp, "SALARY|80000|99999999|Financial confidence detected. Wedding decorator is now interested.\n");
    fprintf(fp, "HOBBY|0|0|Hobby please. Sleeping is valid but not very romantic.\n");
    fprintf(fp, "HOBBY|0|0|Enter hobby. This helps us find your partner in crime.\n");
    fprintf(fp, "MARITAL|0|0|Marital status please. Honesty is the best wedding decoration.\n");
    fprintf(fp, "PREFAGE|0|0|Preferred age range. Keep it realistic, this is not a time machine.\n");
    fprintf(fp, "PREFDISTRICT|0|0|Preferred district. Love may be blind, but bus fare is real.\n");
    fprintf(fp, "PREFEDUCATION|0|0|Preferred education. Cupid is opening the academic filter.\n");
    fprintf(fp, "PREFPROFESSION|0|0|Preferred profession. Dream partner loading...\n");
    fprintf(fp, "REGISTER_DONE|0|0|Registration complete. Your biodata has entered the love database.\n");
    fprintf(fp, "REGISTER_DONE|0|0|Profile saved. Somewhere, destiny just refreshed the page.\n");
    fprintf(fp, "LOGIN_SUCCESS|0|0|Login successful. Welcome back, romantic researcher.\n");
    fprintf(fp, "LOGIN_SUCCESS|0|0|Access granted. Your heart dashboard is ready.\n");
    fprintf(fp, "LOGIN_FAIL|0|0|Wrong email or password. Even Cupid could not verify this.\n");
    fprintf(fp, "LOGIN_FAIL|0|0|Login failed. Maybe the password is hiding from commitment.\n");
    fprintf(fp, "MATCH_HIGH|0|0|High match! Family group chat may explode soon.\n");
    fprintf(fp, "MATCH_HIGH|0|0|Excellent match. Start practicing respectful introduction lines.\n");
    fprintf(fp, "MATCH_MID|0|0|Decent match. Needs conversation, tea, and maybe snacks.\n");
    fprintf(fp, "MATCH_MID|0|0|Medium match. Potential exists, drama level unknown.\n");
    fprintf(fp, "MATCH_LOW|0|0|Low match. Better as neighbors in a database.\n");
    fprintf(fp, "MATCH_LOW|0|0|Compatibility is shy today. Try another profile.\n");
    fprintf(fp, "LOVE_LOW|0|0|Love score low. Friendship subscription recommended.\n");
    fprintf(fp, "LOVE_LOW|0|0|The calculator says: focus on assignments first.\n");
    fprintf(fp, "LOVE_MID|0|0|Love score medium. There is hope, but recharge required.\n");
    fprintf(fp, "LOVE_MID|0|0|Not bad! A good conversation can increase this score.\n");
    fprintf(fp, "LOVE_HIGH|0|0|Love score high! Wedding playlist is warming up.\n");
    fprintf(fp, "LOVE_HIGH|0|0|Strong chemistry detected. Calculator is blushing.\n");
    fprintf(fp, "COST_LOW|0|0|Budget wedding detected. Simple, sweet, and financially peaceful.\n");
    fprintf(fp, "COST_MID|0|0|Medium wedding cost. Relatives will eat happily.\n");
    fprintf(fp, "COST_HIGH|0|0|High wedding cost. Wallet needs emotional support.\n");
    fprintf(fp, "ADMIN|0|0|Admin mode: where romance meets database control.\n");
    fprintf(fp, "ADMIN|0|0|Welcome admin. Please manage love responsibly.\n");

    fclose(fp);
}

void ensureQuoteFile() {
    FILE *fp = fopen(QUOTES_FILE, "r");
    if (fp == NULL) {
        createDefaultQuoteFile();
    } else {
        fclose(fp);
    }
}

int getRandomQuote(char category[], int value, char output[]) {
    FILE *fp;
    char line[300];
    char copyLine[300];
    char *cat, *minText, *maxText, *quoteText;
    int min, max;
    int count = 0;

    output[0] = '\0';

    fp = fopen(QUOTES_FILE, "r");
    if (fp == NULL) {
        strcpy(output, "Quote file missing. Cupid is speechless today.");
        return 0;
    }

    while (fgets(line, 300, fp) != NULL) {
        strcpy(copyLine, line);
        removeNewLine(copyLine);

        cat = strtok(copyLine, "|");
        minText = strtok(NULL, "|");
        maxText = strtok(NULL, "|");
        quoteText = strtok(NULL, "\n");

        if (cat != NULL && minText != NULL && maxText != NULL && quoteText != NULL) {
            min = atoi(minText);
            max = atoi(maxText);

            if (strcmp(cat, category) == 0 && value >= min && value <= max) {
                count++;
                if (rand() % count == 0) {
                    strcpy(output, quoteText);
                }
            }
        }
    }

    fclose(fp);

    if (count == 0) {
        strcpy(output, "No quote found, but the program still believes in you.");
        return 0;
    }

    return 1;
}

void showRandomQuote(char category[], int value) {
    char quote[250];
    getRandomQuote(category, value, quote);
    printf("\n>> %s\n", quote);
}
