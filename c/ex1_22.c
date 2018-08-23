#include <stdio.h>

#define MAXLINE 1000
#define LINELIMIT 20

/*
 * The code looks awful
 * I'll fix it later...
 */

int readline(char line[], int maxline) {
    int c, i;

    for (i = 0; i < maxline && (c = getchar()) != EOF; ++i) {
        if (c == '\t') { c = ' '; }

        line[i] = (char) c;

        if (i == 0 && c == ' ') { --i; continue; }
        if (i > 0 && c == ' ' && line[i-1] == ' ') { --i; continue; }
        if (i > 0 && c == '\n' && line[i-1] == ' ') { --i; break;}
        if (c == '\n') { break; }
    }

    line[i] = '\0';

    return i+1;
}

int nextword(char line[], int maxline, int start) {
    int len = 0;
    for (int i = start; i < maxline; ++i) {
        if (line[i] == ' ' || line[i] == '\0')
            break;
        else
            ++len;
    }

    return len;
}

int printword(char line[], int start, int len, int maxline, int freespace) {
    if (len < freespace) {
        if (freespace != maxline) {
            putchar(' ');
            --freespace;
        }

        for (int i = start; i < start + len; ++i)
            putchar(line[i]);

        freespace -= len;
    } else if (len >= freespace && len < maxline) {
        putchar('\n');
        for (int i = start; i < start + len; ++i)
            putchar(line[i]);

        freespace = maxline - len;
    } else if (len > maxline) {
        for (int i = start; i < start + len; ++i) {
            if (freespace == 1) {
                putchar('/');
                putchar('\n');
                freespace = maxline;
            }
            putchar(line[i]);
            --freespace;
        }
    }

    return freespace;
}

int main() {
    char line[MAXLINE];
    int len, wlen;
    int freespace = LINELIMIT;

    while ((len = readline(line, MAXLINE)) > 1) {
        for (int i = 0; i < len; i++) {
            wlen = nextword(line, MAXLINE, i);
            freespace = printword(line, i, wlen, LINELIMIT, freespace);
            i = i + wlen;
        }
    }

    return 0;
}