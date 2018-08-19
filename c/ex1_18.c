#include <stdio.h>

#define MAXLINE 1000


void printline(char line[], int len) {
    len = len - 1;
    for (int i = len; i >= 0; --i) {
        if (line[len] == '\n' || line[len] == ' ' || line[len] == '\t')
            --len;
        else
            break;
    }

    for (int i = 0; i <= len; ++i) {
        putchar(line[i]);
    }

    if (len > 0)
        putchar('\n');
}

int main() {
    char line[MAXLINE];
    int i = 0;
    int c;

    while ((c = getchar()) != EOF) {
        line[i] = (char) c;
        ++i;

        if (c == '\n') {
            printline(line, i);
            i = 0;
        }
    }
}