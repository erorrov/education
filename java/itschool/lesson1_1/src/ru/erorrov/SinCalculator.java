package ru.erorrov;

class SinCalculator {

    double easyWay(double x) {
        return Math.sin(x);
    }

    double calculateWithForLoop (double x, int n) {
        double result = 0D;
        double numerator = x;
        double denominator = 1D;
        boolean isPlus = false;

        for (int i = 1; i <= n; i++) {
            numerator *= x;
            denominator *= (i - 1);
            if (isPlus)
                result += numerator / denominator;
            else
                result -= numerator / denominator;

            isPlus = isPlus ? false : true;
        }

        return result;
    }

}