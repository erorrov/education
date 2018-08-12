#include <stdio.h>

#define ALPHABET 127
#define COLUMN_CHAR "█"

main() {
    int c;

    int counters[ALPHABET];
    int symbols[ALPHABET];
    int used = 0;
    int position = -1;

    for (int i = 0; i < ALPHABET; ++i) {
        counters[i] = 0;
        symbols[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        position = -1;
        for (int i = 0; i <= used; ++i) {
            if (symbols[i] == c) {
                position = i;
            }
        }

        if (position == -1) {
            symbols[used] = c;
            position = used;
            ++used;
        }

        ++counters[position];
    }

    for (int i = 0; i < used; ++i) {
        if (symbols[i] == -1 && counters[i] == -1)
            break;

        if (symbols[i] == '\n')
            printf("%-2s ", "\\n");
        else if (symbols[i] == '\t')
            printf("%-2s ", "\\t");
        else
            printf("%-2c ", symbols[i]);


        for (int j = 0; j != counters[i]; ++j) {
            printf(COLUMN_CHAR);
        }

        printf("\n");
    }
}