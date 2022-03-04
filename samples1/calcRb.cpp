
#include <print.h>

double calcRb(double Vcc, double hfe, double Ic)
{
    double Rb = (Vcc - 0.7) / (Ic / hfe);

    return Rb;
}

int main()
{
    double result = .0;

    result = calcRb(5.0, 330.0, 0.25);
    print("%f", result);
    
    result = calcRb(5.0, 330.0, 0.50);
    print("%f", result);

    result = calcRb(5.0, 330.0, 0.75);
    print("%f", result);

    result = calcRb(5.0, 330.0, 1.0);
    print("%f", result);

    result = calcRb(5.0, 330.0, 1.25);
    print("%f", result);

    return 0;
}


