#include <stdio.h>

#define MAXLINE 1000
#define LIMIT 80

int readline(char s[], int maxline);

int main() {
    char line[MAXLINE];
    int len;

    while ((len = readline(line, MAXLINE)) > 0) {
        if (len > LIMIT) {
            printf("%s", line);
        }
    }
    
    return 0;
}

int readline(char s[], int maxline) {
    int c, i;

    for (i = 0; i < maxline-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}
