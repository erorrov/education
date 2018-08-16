#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void reverse(char s[], int len);

int main() {
    int c;
    char line[MAXLINE];
    int len = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            reverse(line, len);

            for (int n = 0; n < len; ++n)
                putchar(line[n]);

            putchar('\n');
            len = 0;
        } else {
            line[len] = (char) c;
            ++len;
        }
    }

}

void reverse(char s[], int len) {
    char tmp[len];

    for (int i = len; i >= 0; --i) {
        tmp[len-i] = s[i-1];
    }

    for (int i = 0; i < len; i++) {
        s[i] = tmp[i];
    }
}