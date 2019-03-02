#include <stdio.h>

int main() {
    int spaces = 0;
    int tabs = 0;
    int lines = 0;

    int c;

    while ((c = getchar()) != EOF)
        if (c == ' ')
            ++spaces;
        else if (c == '\t')
            ++tabs;
        else if (c == '\n') 
            ++lines;

    printf("\nspaces = %d\ntabs = %d\nnewline characters = %d\n", spaces, tabs, lines);
    
    return 0;
}