#include <stdio.h>

#define MAX_ERR_COUNT 1000

#define OUT 0
#define IN 1

#define EXPECTED_EXPRESSION_PAREN 0
#define EXPECTED_EXPRESSION_BRACE 1
#define EXPECTED_EXPRESSION_BRACKET 2
#define SINGLE_QUOTE 3
#define DOUBLE_QUOTE 4
#define PAREN_OPEN 5
#define BRACE_OPEN 6
#define BRACKET_OPEN 7

int err_counter = 0;
int err_lines[MAX_ERR_COUNT];
int err_codes[MAX_ERR_COUNT];

int paren = 0;      // ()
int brace = 0;      // {}
int bracket = 0;    // []

int paren_open_line = -1;
int brace_open_line = -1;
int bracket_open_line = -1;

int squote = OUT;   // '
int dquote = OUT;   // "
int quote_open_line = -1;

void add_err(int line, int code) {
    if (err_counter >= MAX_ERR_COUNT)
        return;
    
    if (err_lines[err_counter-1] == line && err_codes[err_counter-1] == code)
        return;
    
    err_lines[err_counter] = line;
    err_codes[err_counter] = code;
    ++err_counter;
}

void read_code(void) {
    int c;
    int line = 0;
    while ((c = getchar()) != '1') {
        if (c != '\'' && squote == IN) { continue; }
        if (c != '"' && dquote == IN) { continue; }
        
        switch (c) {
            case '(':
                if (paren_open_line == -1) paren_open_line = line;
                ++paren;
                break;
                
            case '{':
                if (brace_open_line == -1) brace_open_line = line;
                ++brace;
                break;
                
            case '[':
                if (bracket_open_line == -1) bracket_open_line = line;
                ++bracket;
                break;
                
            case ')':
                if (paren == 1) { paren_open_line = -1; }
                else if (paren <= 0) { add_err(line, EXPECTED_EXPRESSION_PAREN); }
                --paren;
                break;
                
            case '}':
                if (brace == 1) { brace_open_line = -1; }
                else if (brace <= 0) { add_err(line, EXPECTED_EXPRESSION_BRACE); }
                --brace;
                break;
                
            case ']':
                if (bracket == 1) { bracket_open_line = -1; }
                else if (bracket <= 0) { add_err(line, EXPECTED_EXPRESSION_BRACKET); }
                --bracket;
                break;
                
            case '\'':
                squote = squote == OUT ? IN : OUT;
                quote_open_line = line;
                break;
                
            case '\"':
                dquote = dquote == OUT ? IN : OUT;
                quote_open_line = line;
                break;
                
            case '\n':
                ++line;
                break;
                
            default:
                break;
        }
        
    }
}

void check_errs(void) {
    if (squote == IN)
        add_err(quote_open_line, SINGLE_QUOTE);
    
    if (dquote == IN)
        add_err(quote_open_line, DOUBLE_QUOTE);
    
    if (paren != 0 && paren_open_line != -1)
        add_err(paren_open_line, PAREN_OPEN);
    
    if (brace != 0 && brace_open_line != -1)
        add_err(brace_open_line, BRACE_OPEN);
    
    if (bracket != 0 && bracket_open_line != -1)
        add_err(bracket_open_line, BRACKET_OPEN);
}

void print_errs(void) {
    const char *desc[8];
    desc[0] = "unbalanced parenthesis";
    desc[1] = "unbalanced brace";
    desc[2] = "unbalanced bracket";
    desc[3] = "single quote symbol is not closed";
    desc[4] = "double quote symbol is not closed";
    desc[5] = "parenthesis is not closed";
    desc[6] = "brace is not closed";
    desc[7] = "bracket is not closed";
    
    for (int i = 0; i < err_counter; ++i) {
        printf("ERROR: %s on line %d\n", desc[err_codes[i]], err_lines[i]+1);
    }
}

int main() {
    read_code();
    check_errs();
    print_errs();
    
    return err_counter;
}
