#include <stdio.h>

main() {
    int c = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\\') { 
            putchar('\\'); 
            putchar('\\'); 
        } else if (c == '\t') { 
            putchar('\\'); 
            putchar('t'); 
        } else if (c == '\b') { 
            putchar('\\'); 
            putchar('b'); 
        } else {
            putchar(c);
        }
    }
}