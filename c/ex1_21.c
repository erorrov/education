#include <stdio.h>
#include <stdbool.h>

#define MAXLINE 1000
#define TABSIZE 8

bool chekline(char line[], int len) {
    for (int i = 0; i < len; ++i) {
        if (line[i] != ' ' && line[i] != '\n')
            return false;
    }
    return true;
}

void printline(char line[], int len) {
    int inrow = 0;
    for (int i = 0; i < len; ++i) {
        if (line[i] != '\n')
            ++inrow;
        if (inrow == TABSIZE) {
            putchar('\t');
            inrow = 0;
        }
    }

    for (int i = inrow; i > 0; --i) {
        putchar(' ');
    }
}

int main() {
    char line[MAXLINE];
    int i = 0;
    int c;

    while ((c = getchar()) != EOF) {
        line[i] = (char) c;
        ++i;

        if (c == '\n') {
            if (chekline(line, i))
                printline(line, i);
            i = 0;
        }
    }
}

