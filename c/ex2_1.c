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
    printf("%-15s %-20d %-20d\n", "signed int", INT_MIN, INT_MAX);
    printf("%-15s %-20li %-20li\n", "signed long", LONG_MIN, LONG_MAX);
    
    printf("\nComputing...\n"); //char, short, int, long, double, float
    
    char ch = 0;
    while (++ch > 0);
    short sh = 0;
    while (++sh > 0);
    int in = 0;
    while (++in > 0);
    
    printf("%-15s %-20d %-20u\n", "unsigned int", 0, in * -2 - 1);
    printf("%-15s %-20d %-20d\n", "unsigned short", 0,  sh * -2 - 1);
    printf("%-15s %-20d %-20d\n", "unsigned char", 0,  ch * -2 - 1);
    printf("%-15s %-20d %-20d\n", "signed char", ch,  -ch - 1);
    printf("%-15s %-20d %-20d\n", "signed short", sh,  -sh - 1);
    printf("%-15s %-20d %-20d\n", "signed int", in,  -in - 1);
    
    //TODO: float, double, long
}
