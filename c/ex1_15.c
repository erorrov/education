#include <stdio.h>

int main() {
    /* Перепишите программу преобразования температур из раздела 1.2
     * так, чтобы само преобразование выполнялось функцией. */

    float fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        printf("%3.0f %6.1f\n", fahr, convert(fahr));
        fahr = fahr + step;
    }

    return 0;
}

double convert(int fahr) {
    return (5.0/9.0) * (fahr-32.0);
}