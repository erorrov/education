#include <stdio.h>

#define OUT 0
#define IN 1

/*
 * The code looks awful
 * I'll fix it later...
 */

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
    int parenLineFirst = -1;
    int braceLineFirst = -1;
    int bracketLineFirst = -1;
    int charLiteralLine = -1;
    int strMarkLine = -1;
    
    int parenLineLast = -1;
    int braceLineLast = -1;
    int bracketLineLast = -1;
    
    int c;
    
    while ((c = getchar()) != '1') {
        //TODO: escape
        if (charLiteral == IN && c != '\'') { continue; }
        if (strMark == IN && c != '"') { continue; }
        
        switch (c) {
            case '\n':
                ++line;
                break;
                
            case '(':
                parenLineLast = line;
                ++paren;
                break;
                
            case ')':
                if (paren <= 0 && parenLineFirst == -1) { parenLineFirst = line; }
                --paren;
                break;
                
            case '{':
                braceLineLast = line;
                ++brace;
                break;
                
            case '}':
                if (brace <= 0 && braceLineFirst == -1) { braceLineFirst = line; }
                --brace;
                break;
                
            case '[':
                bracketLineLast = line;
                ++bracket;
                break;
                
            case ']':
                if (bracket <= 0 && bracketLineFirst == -1) { bracketLineFirst = bracket; }
                --bracket;
                break;
                
            case '\'':
                charLiteral = charLiteral == OUT ? IN : OUT;
                charLiteralLine = line;
                break;
                
            case '"':
                strMark = strMark == OUT ? IN : OUT;
                strMarkLine = line;
                break;
                
            default:
                break;
        }
    }
    
    
    if (parenLineFirst != -1)
        printf("ERROR: unbalanced parenthesis on line %d\n", parenLineFirst+1);
    if (braceLineFirst != -1)
        printf("ERROR: unbalanced brace on line %d\n", braceLineFirst+1);
    if (bracketLineFirst != -1)
        printf("ERROR: unbalanced bracket on line %d\n", bracketLineFirst+1);
    
    if (charLiteral != OUT)
        printf("ERROR: single quote symbol is not closed on line %d\n", charLiteralLine+1);
    if (strMark != OUT)
        printf("ERROR: double quote symbol is not closed on line %d\n", strMarkLine+1);
    
    if (paren != 0 && parenLineFirst == -1)
        printf("ERROR: parenthesis is not closed on line %d\n", parenLineLast+1);
    if (brace != 0 && braceLineFirst == -1)
        printf("ERROR: brace is not closed on line %d\n", braceLineLast+1);
    if (bracket != 0 && bracketLineFirst == -1)
        printf("ERROR: bracket is not closed on line %d\n", bracketLineLast+1);
    
    //TODO: fix it
    return 0;
}
