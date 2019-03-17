#include <stdio.h>

int main() {
    int c, i, j;
    int ascii[128];

    for (i = 0; i < 128; ++i)
        ascii[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c < 128)
            ++ascii[c];
    }

    for (i = 0; i < 128; ++i) {
        if (ascii[i] > 0) {
            if (i == '\n')
                printf("\\n ");
            else if (i == '\t')
                printf("\\t ");
            else if (i == ' ')
                printf(" ␣ ");
            else
                printf("%2c ", i);

            for (j = 0; j < ascii[i]; ++j) {
                printf("█");
            }

            printf("\n");
        }
    }

    return 0;
}