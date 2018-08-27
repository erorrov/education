#include <stdio.h>

#define MAXLINE 1000

int readline(char line[], int maxline) {
    int c;
    int len;
    for (len = 0; len < maxline && (c = getchar()) != EOF && c != '\n'; ++len) {
        line[len] = (char) c;
    }

    line[len] = '\n';
    return len + 1;
}

int main() {
    char line[MAXLINE];
    int len = 0;

    int inStr = 0;
    int isOLComment = 0;
    int isMLComment = 0;

    while ((len = readline(line, MAXLINE)) > 0) {
        for (int i = 0; i < len; ++i) {

            if ((line[i] == '\'' || line[i] == '"') && isOLComment == 0 && isOLComment == 0) {
                inStr = inStr == 0 ? 1 : 0;
                putchar(line[i]);
                continue;
            }

            if (i+1 <= len && inStr == 0) {
                if (line[i] == '/' && line[i+1] == '/' && isMLComment == 0) {
                    isOLComment = 1;
                    ++i;
                } else if (isOLComment == 1 && line[i+1] == '\n') {
                    isOLComment = 0;
                    ++i;
                } else if (line[i] == '/' && line[i+1] == '*' && isOLComment == 0) {
                    isMLComment = 1;
                    ++i;
                } else if (line[i] == '*' && line[i+1] == '/') {
                    isMLComment = 0;
                    ++i;
                } else {
                    if (isOLComment != 1 && isMLComment != 1) {
                        putchar(line[i]);
                    }
                }
            }

        }
    }
}