#include <stdio.h>

#define TABSIZE 8

int main() {
    int c;
    int column = TABSIZE;

    while ((c = getchar()) != EOF) {
        if (c != '\t') {
            column = column > 0 ? --column : TABSIZE-1;
            putchar(c);
        } else {
            for (int i = column; column > 0; --column) {
                putchar(' ');
            }

        }
    }
    
    return 0;
}
