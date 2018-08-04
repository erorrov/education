#include <stdio.h>

main() {
    int c = 0;
    int lastChar = NULL;

    while ((c = getchar()) != EOF) {
        if (!(lastChar == ' ' && c == ' ')) {
            putchar(c);
        }

        lastChar = c;
    }
}