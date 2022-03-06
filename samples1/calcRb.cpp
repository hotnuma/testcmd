
#include <print.h>

double calcRb(double Vcc, double Vbe, double Ic, double hfe)
{
    double Rb = (Vcc - Vbe) / (Ic / hfe);

    return Rb;
}

int main()
{
    double result = .0;

    result = calcRb(5.0, 0.7, 0.25, 250);
    print("%f", result);

    result = calcRb(5.0, 0.8, 0.50, 200);
    print("%f", result);

    result = calcRb(5.0, 0.9, 0.75, 150);
    print("%f", result);

    result = calcRb(5.0, 1.0, 1.0, 100);
    print("%f", result);

    result = calcRb(5.0, 1.2, 1.25, 30);
    print("%f", result);

    return 0;
}


