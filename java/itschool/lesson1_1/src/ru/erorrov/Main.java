package ru.erorrov;

public class Main {

    public static void main(String args[]) {
        SinCalculator sinCalculator = new SinCalculator();
        double result = sinCalculator.calculateWithForLoop(3, 10);
        System.out.println(result); // NaN :(
    }

}
