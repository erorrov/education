#include <stdio.h>

#define OUT 0
#define IN 1

int main() {
    //current line count
    int line = 0;

    //states
    int paren = 0;
    int brace = 0;
    int bracket = 0;
    int charLiteral = OUT;
    int strMark = OUT;

    //lines with errors
    int parenLine = -1;
    int braceLine = -1;
    int bracketLine = -1;
    int charLiteralLine = -1;
    int strMarkLine = -1;

    int c;

    while ((c = getchar()) != EOF) {
        //TODO: consider \' and \"
        if (charLiteral == IN && c != '\'') { continue; }
        if (strMark == IN && c != '"') { continue; }

        switch (c) {
            case '\n':
                ++line;
                break;

            case '(':
                ++paren;
                break;

            case ')':
                if (paren <= 0) { parenLine = line; }
                --paren;
                break;

            case '{':
                ++brace;
                break;

            case '}':
                if (brace <= 0) { braceLine = line; }
                --brace;
                break;

            case '[':
                ++bracket;

            case ']':
                if (bracket <= 0) { bracketLine = bracket; }
                --bracket;

            case '\'':
                charLiteral = charLiteral == OUT ? IN : OUT;
                charLiteralLine = line;

            case '"':
                strMark = strMark == OUT ? IN : OUT;
                strMarkLine = line;

            default:
                break;
        }
    }

    if (parenLine != -1)
        printf("ERROR: 1 in line %d\n", parenLine);
    if (braceLine != -1)
        printf("ERROR: 2 in line %d\n", braceLine);
    if (bracketLine != -1)
        printf("ERROR: 3 in line %d\n", bracketLine);
    if (charLiteral != OUT)
        printf("ERROR: 4 in line %d\n", charLiteralLine);
    if (strMark != OUT)
        printf("ERROR: 5 in line %d\n", strMarkLine);

    return parenLine == -1 && braceLine == -1 && bracketLine == -1 && charLiteral == OUT && strMark == OUT ? 0 : 1;
}
