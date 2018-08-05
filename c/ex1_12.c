#include <stdio.h>

main() {
    int c = 0;
    int state = 0;
    int lastChar = NULL;

    while ((c = getchar()) != EOF) {
        if (state == 1 && c == ' ') {
            putchar('\n');
            state = 0;
        } else if (lastChar == NULL || lastChar == ' ' && c == ' ') {
            state = 0;
        } else {
            state = 1;
            putchar(c);
        }

        lastChar = c;
    }
}