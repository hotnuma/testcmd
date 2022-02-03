#include <math.h>
#include <float.h>
#include <print.h>

int main()
{
    double T1 = 13.10;
    double R1 = 17240.0;
    double T2 = 25.0;
    double R2 = 10830.0;

    double TK1 = T1 + 273.15;
    double TK2 = T2 + 273.15;
    double L1 = log(R1 / R2);
    double Y1 = 1.0 / TK1;
    double Y2 = 1.0 / TK2;

    double beta = L1 / (Y1 - Y2);

    print("beta : %f", beta);

    return 0;
}


