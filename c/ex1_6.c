#include <stdio.h>

int main() {
    printf("getchar() != EOF is %s\n", getchar() != EOF ? "true" : "false");
    return 0;
}