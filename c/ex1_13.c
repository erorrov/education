#include <stdio.h>

#define COLUMN_CHAR "█"

main() {
    int c, i, j;
    int ndigit[10];

    for (i = 0; i < 10; ++i) {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            ++ndigit[c - '0'];
        }
    }

    //horizontal
    for (i = 0; i < 10; ++i) {
        printf("%2d: ", i);
        for (j = 0; j < ndigit[i]; ++j) {
            printf(COLUMN_CHAR);
        }
        printf("\n");
    }

    //vertical
    int max = 0;
    for (i = 0; i < 10; ++i) {
        if (ndigit[i] > max) {
            max = ndigit[i];
        }
    }

    for (i = max; i >= 0; --i) {
        for (j = 0; j < 10; j++) {
            printf(ndigit[j] > i ? COLUMN_CHAR : " ");
            if (j != 9) { printf("\t"); }
        }
        printf("\n");
    }

    for (j = 0; j < 10; j++) {
        printf("%d\t", j);
    }

}