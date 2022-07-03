#include <math.h>
#include <float.h>
#include <print.h>

int main()
{
    double T1 = 0.0;
    double R1 = 33621.0;
    double T2 = 25.0;
    double R2 = 10000.0;
    double T3 = 50.0;
    double R3 = 3588.2;

    double L1 = log(R1);
    double L2 = log(R2);
    double L3 = log(R3);

    double Y1 = 1.0 / (T1 + 273.15);
    double Y2 = 1.0 / (T2 + 273.15);
    double Y3 = 1.0 / (T3 + 273.15);

    double D2 = (Y2 - Y1) / (L2 - L1);
    double D3 = (Y3 - Y1) / (L3 - L1);

    double C = (D3 - D2) * pow((L1 + L2 + L3), -1);
    double B = D2 - (C * (pow(L1, 2) + (L1 * L2) + pow(L2, 2)));
    double A = Y1 - ((B + (pow(L1, 2) * C)) * L1);

    // https://stackoverflow.com/questions/16839658/

    int Digs = DECIMAL_DIG;
    print("double A = %.*e;", Digs, A);
    print("double B = %.*e;", Digs, B);
    print("double C = %.*e;", Digs, C);

    return 0;
}


