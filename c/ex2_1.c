#include <stdio.h>
#include <limits.h>
#include <float.h>

int main () {
    printf("%-15s %-20d %-20lu\n", "unsigned long", 0, ULONG_MAX);
    printf("%-15s %-20d %-20u\n", "unsigned int", 0, UINT_MAX);
    printf("%-15s %-20d %-20d\n", "unsigned short", 0, USHRT_MAX);
    printf("%-15s %-20d %-20d\n", "unsigned char", 0, UCHAR_MAX);
    printf("%-15s %-20d %-20d\n", "signed char", SCHAR_MIN, SCHAR_MAX);
    printf("%-15s %-20d %-20d\n", "signed short", SHRT_MIN, SHRT_MAX);
    printf("%-15s %-20d %-20d\n", "int", INT_MIN, INT_MAX);
    printf("%-15s %-20li %-20li\n", "signed long", LONG_MIN, LONG_MIN);
}
