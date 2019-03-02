#include <stdio.h>

int main() {
    int c;
    int last = 0;

    while ((c = getchar()) != EOF)
        if ((c == ' ' && last != ' ') || c != ' ')  {
            putchar(c);
            last = c;
        }

    return 0;
}