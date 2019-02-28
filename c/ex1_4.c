#include <stdio.h>

int main() {
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("%3s %6s\n", "C", "F");

    celsius = lower;
    while (celsius <= upper) {
        fahr = (celsius * 9/5) + 32;
        printf("%3d %6d\n", celsius, fahr);
        celsius = celsius + step;
    }

    return 0;
}
