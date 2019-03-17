#include <stdio.h>

#define MAX_WORD_LEN 20

int main() {
    int c, i, j;
    int len = 0;
    int max = 0;
    int nwords[MAX_WORD_LEN+1];

    for (i = 0; i < MAX_WORD_LEN; ++i)
        nwords[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            nwords[len] += (len > 0 && len < MAX_WORD_LEN) ? 1 : 0;
            max = (max < len && len < MAX_WORD_LEN) ? len : max;
            len = 0;
        } else {
            ++len;
        }
    }

    //horizontal
    for (i = 1; i <= max; ++i) {
        printf("%02d: ", i);

        for (j = 0; j < nwords[i]; ++j)
            printf("█");

        putchar('\n');
    }

    //vertical
    int lines = 0;

    for (i = 0; i <= max; ++i)
        lines = (nwords[i] > lines) ? nwords[i] : lines;

    for (; lines > 0; --lines) {
        for (j = 1; j <= max; ++j)
            printf((nwords[j] >= lines) ? "█\t" : " \t");

        printf("\n");
    }

    for (i = 1; i <= max; ++i)
        printf("%0d\t", i);

    return 0;
}