#include <stdio.h>

main() {
    int spaces = 0;
    int tabs = 0;
    int lines = 0;

    int c = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') { 
            ++spaces; 
        } else if (c == '\t') { 
            ++tabs; 
        } else if (c == '\n') { 
            ++lines; 
        }
    }

    printf("spaces = %d\ntabs = %d\nlines = %d (actually %d)",
           spaces, tabs, lines, lines + 1);
}