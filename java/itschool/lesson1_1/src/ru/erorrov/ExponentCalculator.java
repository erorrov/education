package ru.erorrov;

// 1 + x/1! + x^2/2!...

class ExponentCalculator {

    double calculateWithForLoop(int x, int addendNumber) {
        double result = 1D;
        double numerator = 1D;
        double denominator = 1D;

        for (int currentAddend = 2; currentAddend <= addendNumber; currentAddend++) {
            numerator *= x;
            denominator *= (currentAddend - 1);
            result += numerator/denominator;
        }

        return result;
    }

    double calculateWithWhileLoop(int x, double precision) {
        double result = 1D;
        double numerator = x;
        double denominator = 1D;
        double addend = numerator / denominator;
        int addendNumber = 2;

        while (addend > precision) {
            result += addend;
            numerator *= x;
            denominator *= addendNumber;
            addend = numerator / denominator;
            addendNumber++;
        }

        return result;
    }

}
